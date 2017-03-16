inp = open(r"F:\Nir\Downloads\A-small-attempt0.in",'r')
out = open(r"F:\Nir\Downloads\njy\q1.out", 'w')
l = inp.readlines()

a = []
d2w = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
presentor = ['Z','O','W','R','U','F','X','S','G','N']
order = [0,2,4,6,8,1,3,7,9,5]
t = int(l[0])
for i in range(t):
    s = l[i+1]
    x = {c:s.count(c) for c in [chr(i) for i in range(ord('A'), ord('Z')+1)]}
    y = {i:0 for i in range(10)}
    
    for dig in order:
        while x[presentor[dig]] != 0:
            y[dig] += 1
            for c in d2w[dig]:
                x[c] -= 1

    r = "".join([str(i)*y[i] for i in range(10)])
    a.append(r)

for i in range(t):
    out.write("Case #{0}: {1}\n".format(i+1,a[i]))