vowels = ['a','e','i','o','u']

'''def sub(x):
    if(x < n):
        return 0
    diff = x-n+1
    return (diff)*(diff+1)/2

def dvq(s):
    ret = 0
    if(len(s) < n):
        return ret
    mid = len(s)/2
    left = dvq(s[:mid])
    right = dvq(s[mid:])
    if(left > 0):
        ret += mid
    if(right > 0):
        ret += mid
    ret += left+right
    tmp = 0
    i = mid-1
    while(i >= 0 and s[i] not in vowels):
        i -= 1
        tmp += 1
    i = mid
    while(i < len(s) and s[i] not in vowels):
        i += 1
        tmp += 1
    ret += sub(tmp)
    return ret'''

cas = int(raw_input().strip())

for cc in range(1,cas+1):
    print 'Case #' + str(cc) + ':',
    inp = raw_input().strip().split()
    n = int(inp[1])
    name = inp[0]
    left = 0
    right = 0
    ans = 0
    cons = 0
    while(right < len(name)):
        while(cons < n and right < len(name)):
            if(name[right] not in vowels):
                cons += 1
            else:
                cons = 0
            right += 1
        if(cons >= n):
            ans += (right-n-left+1)*(len(name)-right+1)
        #print left,right,(right-n-left+1)*(len(name)-right+1)
        left = right-n+1
        cons -= 1
    print ans
        
        
