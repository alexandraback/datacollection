import sys
t=int(input())
for i in range(t):
    st=raw_input()
    temp=''
    for j in range(len(st)):
        if j==0:
            temp+=st[j]
            continue
        if st[j] <= temp[j-1] or temp[0]>st[j]:
            temp=temp+st[j]
        else:
            temp=st[j]+temp
    print("Case #%d: %s" % (i+1, temp))
