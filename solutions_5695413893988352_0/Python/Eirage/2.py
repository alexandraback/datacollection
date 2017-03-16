
T = int(input())  
#n, m = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case

for k in range (T):
    a,b = raw_input().split(" ")
    n = len(a)
    ans = ''


    i = 0
    a0 = ''
    b0 = ''
    ansa = ''
    ansb = ''
    maxdiff = int('9' * (n-i))

    while i < n:
        if a[i] == b[i] and a[i] != '?':
            a0 += a[i]
            b0 += b[i]

        elif a[i]!='?' and b[i]!='?':
            aa = a[i]
            bb = b[i]
            if a[i] > b[i]:
                for j in xrange(i+1,n):
                    if a[j] == '?':
                        aa+=('0')
                    else:
                        aa += a[j]
                    if b[j] == '?':
                        bb+=('9')
                    else:
                        bb+=b[j]
            elif a[i] < b[i]:
                for j in xrange(i+1,n):
                    if a[j] == '?':
                        aa+=('9')
                    else:
                        aa += a[j]
                    if b[j] == '?':
                        bb+=('0')
                    else:
                        bb+=b[j]

            diff = abs(int(aa) - int(bb))
            if diff < maxdiff or (diff == maxdiff and (ansa > a0+aa or (ansa== a0+aa and ansb > b0+bb))):
                maxdiff = diff
                ansa = a0+aa
                ansb = b0+bb
            break
        elif a[i] =='?' and b[i]=='?':
            #1
            aa = '1'
            bb = '0'
            for j in xrange(i+1,n):
                if a[j] == '?':
                    aa+=('0')
                else:
                    aa += a[j]
                if b[j] == '?':                        
                    bb+=('9')
                else:
                    bb+=b[j]
            diff = abs(int(aa)-int(bb))
            if diff < maxdiff or (diff == maxdiff and (ansa > a0+aa or (ansa== a0+aa and ansb > b0+bb))):
                maxdiff = diff
                ansa = a0+aa
                ansb = b0+bb

            aa = '0'
            bb = '1'

            for j in xrange(i+1,n):
                if a[j] == '?':
                    aa+=('9')
                else:
                    aa += a[j]
                if b[j] == '?':                        
                    bb+=('0')
                else:
                    bb+=b[j]
            diff = abs(int(aa)-int(bb))
            if diff < maxdiff or (diff == maxdiff and (ansa > a0+aa or (ansa== a0+aa and ansb > b0+bb))):
                maxdiff = diff
                ansa = a0+aa
                ansb = b0+bb



            a0+=('0')
            b0+=('0')
        else:
            #case -1
            if a[i] == '?':
                y = int(b[i])
                x = y + 1
            elif b[i] == '?': 
                x = int(a[i])
                y = x - 1
            aa = str(x)
            bb = str(y)
            for j in xrange(i+1,n):
                if a[j] == '?':
                    aa+=('9')
                else:
                    aa += a[j]
                if b[j] == '?':                        
                    bb+=('0')
                else:
                    bb+=b[j]
            diff = abs(int(aa)-int(bb))
            if diff < maxdiff or (diff == maxdiff and (ansa > a0+aa or (ansa== a0+aa and ansb > b0+bb))):
                maxdiff = diff
                ansa = a0+aa
                ansb = b0+bb
            #case 1
            if a[i] == '?':
                y = int(b[i])
                x = y - 1
            elif b[i] == '?': 
                x = int(a[i])
                y = x + 1
            aa = str(x)
            bb = str(y)
            for j in xrange(i+1,n):
                if a[j] == '?':
                    aa+=('0')
                else:
                    aa += a[j]
                if b[j] == '?':                        
                    bb+=('9')
                else:
                    bb+=b[j]
            diff = abs(int(aa)- int(bb))
            if diff < maxdiff or (diff == maxdiff and (ansa > a0+aa or (ansa== a0+aa and ansb > b0+bb))):
                maxdiff = diff
                ansa = a0+aa
                ansb = b0+bb

            #case 0
            if a[i] == '?':
                y = int(b[i])
                x = y
            elif b[i] == '?': 
                x = int(a[i])
                y = x
            a0 += str(x)
            b0 += str(y)

        i+=1
    if i == n:
        maxdiff = 0
        ansa = a0
        ansb = b0


    print "Case #{}: {} {}".format(k+1, ans+ansa,ans+ansb)
    

