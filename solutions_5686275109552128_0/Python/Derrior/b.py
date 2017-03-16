import sys

def main(number):
    n = int(fin.readline().rstrip())
    ans = 179179
    pancakes = list(map(int, fin.readline().rstrip().split()))
    for i in range(1, 1001):
        c = 0
        curr = [0] * n
        for j in range(n):
            
            p = divmod(pancakes[j], i)
            if p[1] == 0:
                
                c += p[0] - 1
                curr[j] = i
            else:
                c += p[0]
                curr[j] = p[1]
        if c:
            curr.append(i)
        ans = min(ans, c + max(curr)) 
        #if i < 10:
            #print(curr, c)
    print("Case #%d: %d"%(number, ans), file=fout)

fin = open("../Downloads/B-small-attempt0.in")
fout = open('b.out', "w")
t = int(fin.readline().rstrip())
for i in range(t):
    main(i + 1)
fout.close()