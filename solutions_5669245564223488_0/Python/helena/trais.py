fc = [1]*101
for i in range(2,101):
    fc[i] = fc[i-1]*i % 1000000007
T = int(input())
for t in range(1,T+1):
    n = int(input())
    s = list(input().split())
    b = [0]*26 
    e = [0]*26 
    h = [0]*26 
    m = [0]*26 
    c = 0
    f = True
    for i in range(len(s)):
            ss = set(s[i])
            if len(ss)==1:
                h[ord(s[i][0])-ord('a')] += 1
                
            else:
                if s[i][0]==s[i][-1]:
                    f = False
                    break
                if b[ord(s[i][0])-ord('a')] == 1 or m[ord(s[i][0])-ord('a')] >= 1:
                    f = False
         #           print(s[i],1)
                    break
                else:
                    b[ord(s[i][0])-ord('a')] = 1
                if e[ord(s[i][-1])-ord('a')] == 1 or m[ord(s[i][-1])-ord('a')] >= 1:
                    f = False
           #         print(s[i],2)
                    break
                else: 
                    e[ord(s[i][-1])-ord('a')] = 1
                
                for k in range(1,len(s[i])-1):  
                    if s[i][k]!=s[i][k-1]:
                        if len(set(s[i][k:])) == 1:
                            break                        
                        if m[ord(s[i][k])-ord('a')] >= 1 or b[ord(s[i][k])-ord('a')] == 1:
                            f = False
           #                 print(s[i],3)
                            break 
                        
                        elif e[ord(s[i][k])-ord('a')] == 1:
           #                 print(s[i],4)
                            f = False
                            break
                        else:
                            m[ord(s[i][k])-ord('a')] = 1
                if not f: break
        
    if f:    
        k = len(s)
        c = 1
        for i in range(26):
   #         print(b[i],e[i],h[i])
            if b[i] == 1 and e[i] == 1 or b[i] == 1 and h[i] >= 1 or e[i]== 1 and h[i] >=1:
                k -= 1
                if b[i] == 1 and h[i] >= 1 and e[i]== 1 and h[i] >=1:
                    k -= 1
            if h[i] > 1:
                k -=(h[i]-1)
            c *= fc[h[i]]
    #        print(c,k)
        if k == 0: c = 0
        else: c *= fc[k]
    print('Case #'+str(t)+':', c % 1000000007)
    
   