#1
def P1(n):
    if n == 0:
        return "INSOMNIA"
    digits = set(str(n))
    s = n
    while len(digits) < 10:
        s += n
        digits.update(set(str(s)))
    return s


inp_filename = r"F:\Nir\Downloads\A-small-attempt1.in"
out_filename = r"F:\Nir\Downloads\res.out"

f = open(inp_filename, 'r')
l = f.readlines()
ou = open(out_filename, 'w')

t = int(l[0])
res = []
for i in range(1,t+1):
    n = int(l[i])
    res.append(P1(n))

for i in range(t):
    print("Case #{0}: ".format(i+1) + str(res[i]))
    ou.write("Case #{0}: ".format(i+1) + str(res[i])+"\n")

ou.close()