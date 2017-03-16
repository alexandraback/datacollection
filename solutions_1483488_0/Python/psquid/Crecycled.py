done = [0]*2000010

f = open("C-small-attempt0.in",'r')
T = int(f.readline())

for i in range(T):
    [A,B] = [int(x) for x in f.readline().strip().split()]
    for n in range(A,B+1): done[n] = 0
    ans = 0
    for n in range(A,B+1):
        if done[n]: continue
        s = str(n)
#        print("\n"+str(n)+" : ")
        count = 1
        for d in range(1,len(s)):
            m = int(s[d:]+s[:d])
            if A <= m and m <= B and n != m:
#                print(m)
                count += 1
                done[m] = 1
        ans += count*(count-1)//2
    print("Case #"+str(i+1)+": "+str(ans))
