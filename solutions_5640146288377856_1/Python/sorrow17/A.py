
def solve(r,c,w):
    ans = 0
    if(r>1):
        ans+=(r-1)*c//w
    if(c/w>1):
        ans+=c//w-1
    ans += w
    if(c%w!=0):
        ans+=1
    return ans
if __name__=='__main__':
    ans = []
    with open('A.in') as f:
        T = int(f.readline())
        for k in range(T):
            r, c, w = [int(x) for x in f.readline().split()]
            ans.append(solve(r, c, w))

    with open('output.txt','w') as f:
        for k,t in enumerate(ans):
            f.write("Case #"+str(k+1)+": "+"{0}\n".format(t))
