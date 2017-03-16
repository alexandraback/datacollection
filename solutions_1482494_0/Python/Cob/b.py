import sys

cases = int(input())
for caseno in range(1, cases + 1):
    n = int(input())
    stars = []
    stars1 = []
    stars2 = []
    for i in range(n):
        newlevel = list(map(int, sys.stdin.readline().split()))
        stars.append(newlevel)
        stars1.append((newlevel[0], i))
        stars2.append((newlevel[1], i))
    
    stars1.sort(key=lambda x: x[0], reverse=False)
    stars2.sort(key=lambda x: x[0], reverse=False)
    visited = [0 for i in range(len(stars))]
    curs = 0  
    cnt = 0
    while len(stars2) > 0:
        i = 0
        rem = []
        while i < len(stars2):
            if curs >= stars2[i][0]:
                idx = stars2[i][1]
                if visited[idx] == 0:
                    curs += 2
                else:
                    curs += 1
                cnt += 1
                star1tmp = (stars[idx][0], idx)
                rem.append((stars2[i], star1tmp))
                i += 1
            else:
                break
        for item in rem:
            stars2.remove(item[0])
            if item[1] in stars1:
                stars1.remove(item[1])
            
        if len(stars2) == 0:
            continue
        
        if len(stars1) > 0 and curs >= stars1[0][0]:
            curs += 1
            idx = stars1[0][1]
            visited[idx] = 1
            cnt += 1
            stars1.remove(stars1[0])
        else:
            print("Case #{0}: Too Bad".format(caseno))
            break
    else:
        print("Case #{0}: {1}".format(caseno, cnt))
     
        
        