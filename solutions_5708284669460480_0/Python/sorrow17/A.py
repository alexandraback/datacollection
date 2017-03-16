next_ = [0]*1000
def pre(s):
    global next_
    next_ = [0]*1000
    for i in range(len(s)):
        tar = i-1
        while tar>0 and s[next_[tar]+1]!=s[i]:
            tar = next_[tar]
        next_[i]=tar
def work(x,s,chars,freq,target):
    if s==0:
        
        bp = 1.0
        for i in x:
            bp*= freq[i]
        count = 0
        for i in range(len(x)):
            if x[i:i+len(target)]==target:
                count += 1
        return bp*count
    else:
        res = 0
        for c in chars:
            res += work(x+c,s-1,chars,freq,target)
        return res
def solve(k,l,s,keys,target):
    freq = dict(zip([chr(i) for i in range(65,65+26)],[0]*26))
    chars = set([])
    for c in keys:
        freq[c] += 1
        chars.add(c)
    for c in freq:
        freq[c] = freq[c]/len(keys)
    print(chars)

    ae = 0
    flag = True
    for c in target:
        if c not in chars:
            flag = False
            break
    if flag:
        pre(target)
        maxx = next_[l-1]+1
        maxx = (s-maxx)/(l-1-next_[l-1])
    else:
        maxx = 0
    ae = work('',s,chars,freq,target)
    return maxx-ae

if __name__=='__main__':
    ans = []
    with open('B.in') as f:
        T = int(f.readline())
        for kk in range(T):
            k, l, s = [int(x) for x in f.readline().split()]
            keys = f.readline().strip()
            target = f.readline().strip()
            tmp = solve(k,l,s, keys, target)
            ans.append(tmp)

    with open('output.txt','w') as f:
        for k,t in enumerate(ans):
            f.write("Case #"+str(k+1)+": "+"{0}\n".format(t))
