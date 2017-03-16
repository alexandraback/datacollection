
inp = open(r"C:\Users\t8319937\Downloads\A-large.in",'r')
out = open(r"C:\Users\t8319937\Downloads\NirYa\q1.out", 'w')
l = inp.readlines()

a = []
t = int(l[0])
for i in range(t):
    s = l[i+1]
    r = s[0]
    for c in s[1:]:
        if ord(c) >= ord(r[0]):
            r = c + r
        else:
            r = r + c
    a.append(r)

for i in range(t):
    out.write("Case #{0}: {1}".format(i+1,a[i]))