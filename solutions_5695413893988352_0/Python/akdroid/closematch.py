t = int(raw_input(''))

for i in range(t):
    
    s1,s2 = raw_input('').split(' ')
    s1=s1.strip()
    s2=s2.strip()
    
    a = 0
    b = 0

    ans1 = ''
    ans2 = ''

    for j in range(len(s1)):
        x = s1[j]
        y = s2[j]
        if(x  == '?' and y == '?'):
            if a == b:
                ans1 += '0'
                ans2 += '0'
                a = a*10
                b = b*10
            elif a < b: 
                ans1 += '9'
                ans2 += '0'
                a = a*10 + 9
                b = b*10
            elif a > b:
                ans1 += '0'
                ans2 += '9'   
                a = a*10
                b = b*10 + 9
        elif x != '?' and y != '?':
            ans1 += x
            ans2 += y
            absdiff = abs(int(x)- int(y))
            if a == b and a != 0:
                if int(x) > int(y) and absdiff >= 5 and s1[j-1] == '?':
                    ans1 = str(a-1) + x
                    a = a - 1
                elif int(x) < int(y) and absdiff > 5 and s2[j-1] == '?':
                    b = b -1
                    ans2 = str(b) + y
            a = a*10 + int(x)
            b = b*10 + int(y)
        elif x == '?':
            if a == b:
                ans1 += y   
                ans2 += y   
                a = a*10 + int(y)
                b = b*10 + int(y)
            elif a < b:
                ans1 += '9' 
                ans2 += y  
                a = a*10 + 9
                b = b*10 + int(y)
            elif a > b:
                ans1 += '0' 
                ans2 += y  
                a = a*10 
                b = b*10 + int(y)
        else:
            if a == b:
                ans1 += x
                ans2 += x   
                a = a*10 + int(x)
                b = b*10 + int(x)
            elif a < b:
                ans1 += x 
                ans2 += '0' 
                a = a*10 + int(x)
                b = b*10
            elif a > b:
                ans1 += x 
                ans2 += '9' 
                a = a*10 + int(x)
                b = b*10 + 9 
        
    print 'Case #%d:'%(i+1),
    print ans1,ans2

