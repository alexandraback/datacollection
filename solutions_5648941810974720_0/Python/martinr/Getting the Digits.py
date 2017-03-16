 
def solve(s):
    def fits(digit, cnt):
        s = set(digit)
        for c in s:
            if not(c in cnt) or (digit.count(c) > cnt[c]):
                return False
        return True
    
    A = ['SIX', 'EIGHT', 'TWO', 'ZERO', 'FIVE',  'THREE', 'FOUR', 'NINE', 'SEVEN', 'ONE']

    D = {'ZERO':'0','ONE':'1', 'TWO':'2', 'THREE':'3','FOUR':'4', 'FIVE':'5', 'SIX':'6', 'SEVEN':'7', 'EIGHT':'8', 'NINE':'9'}
    cnt={}
    for c in set(s):
        cnt[c] = s.count(c)
        
    l = 0
    res = []
    for d in A:         
        while fits(d, cnt):
            res.append(D[d])
            l += len(d)
            for c in d:
                cnt[c] -= 1    
            
    
    res.sort()
    if l <> len(s): 
        print cnt

    return ''.join(res)
        
    
#filespec = "e:/work/code_jam/Getting the Digits.txt"    
filespec = "d:/downloads/A-small-attempt2.in"
#filespec = "d:/downloads/A-large.in"
#filespec = "e:/work/code_jam/test.txt"    
f = open(filespec, 'r')
out = open("e:/work/code_jam/out.txt", 'w')

T = int(f.readline())
for nbr in range(1, T+1):
    s = f.readline().strip()
    
    sol = solve(s)
    s = "Case #%d: %s\n" %(nbr, sol)
    print s,

    out.write(s)
    
f.close()
out.close()
