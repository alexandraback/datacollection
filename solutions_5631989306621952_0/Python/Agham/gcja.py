for x in range(int(input())):
    a=input()
    ans=''
    ans = ans + a[0]
    c = ord(a[0])- ord('A')
    for i in range(1,len(a)):
        q = ord(a[i])- ord('A')
        if q < c:
            ans = ans + a[i]
        else:
            ans = a[i] + ans
            c= ord(a[i])- ord('A')

    print('Case #'+ str(x+1)+': '+ans)
