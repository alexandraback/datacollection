a = input()
b=[]
c=[]

for i in range(a):
    b.append(raw_input())
    c.append('Case #'+str(i+1)+':')
d={}


def func(word):
    j = word[0]
    for i in range(1,len(word)):
        if j[0] > word[i]:
            j = j + word[i]
        else:
            j = word[i] +j
    return j

for k in range(a):
    print c[k],func(b[k])
