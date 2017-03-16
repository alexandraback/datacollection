T=int(input())
for t in range(T):
    a,b = [int(x) for x in input().split()]
    count = 0
    l = [0 for i in range(a,b+1)]
    for n in range(a,b):
        if l[n-a]:
            continue
        l[n-a]=1
        ms = []
        s = str(n)
        c = s[0]
        i = 10
        j = 10**(len(str(n))-1)
        while i<n:
            m = j*(n%i) + (n//i)
            if n<m<=b:
                l[m-a]=1
                ms.append(m)
#                print(n,m)
            i*= 10
            j//=10
        if ms:
            if len(ms)>1:
                case = len(set(ms))
                count+= (case*(case+1))//2
            else:
                count +=1
    print('Case #',t+1,': ',count,sep = '')
