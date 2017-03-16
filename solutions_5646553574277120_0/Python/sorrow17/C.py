
def solve(c,d,v,a):
    ans =0
    count = 1
    for i in range(d):
        while a[i]>count:
            ans +=1
            count += c*count
        count += a[i]*c
    while count<=v :
        ans += 1
        count += c*count
    return ans

if __name__=='__main__':
    ans = []
    with open('C.in') as f:
        T = int(f.readline())
        for k in range(T):
            c, d, v = [int(x) for x in f.readline().split()]
            a = [int(x) for x in f.readline().split()]
            ans.append(solve(c,d,v, a))

    with open('output.txt','w') as f:
        for k,t in enumerate(ans):
            f.write("Case #"+str(k+1)+": "+"{0}\n".format(t))
