


T = int(input())



for casei in range(1, T+1):
    print("Case #",casei,": ",sep="",end="")
    N = int(input())
    topica = {}
    topicb = {}
    topiclist = []
    flag = {}
    for i in range(0,N):
        line = input()
        a, b = line.split(" ")
        topiclist.append((a,b) )
        if topica.get(a):
            topica[a] += 1
        else:
            topica[a] = 1
            flag[a] = False
        if topicb.get(b):
            topicb[b] += 1
        else:
            topicb[b] = 1

    count = 0
    for x in topiclist:
        a = x[0]
        b = x[1]
        if topica[a] >= 2:
            if topicb[b] >= 2:
                count += 1
            else:
                flag[a] = True
        else:
            flag[a] = True
    for k,v in flag.items():
        if not v:
            count -= 1

    print(count)
