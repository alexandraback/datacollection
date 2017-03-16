#P2
def P4(k,c):
    if k == 0 or c == 0:
        return ''
    idx = 0
    res = []
    while idx < k:
        num = 0
        for i in range(c):
            if idx < k:
                num = num*k + idx
                idx += 1
        res.append(num+1) #plus 1 to correct indexes 
    return res

#a = [ [P4(k,c) for c in range(101)] for k in range(101)]

inp_filename = r"F:\Nir\Downloads\D-large.in"
out_filename = r"F:\Nir\Downloads\GCJ\res.out"

f = open(inp_filename, 'r')
st = f.read()
l = st.split('\n')
ou = open(out_filename, 'w')

t = int(l[0])
for i in range(1,t+1):
    k,c,s = [int(v) for v in l[i].split(" ")]
    if s < k/c:
        res = "IMPOSSIBLE"
    else:
        res = " ".join([str(v) for v in P4(k,c)])
    ou.write("Case #{0}: ".format(i) + res + "\n")

f.close()
ou.close()