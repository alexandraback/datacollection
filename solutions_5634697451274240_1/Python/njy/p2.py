#P2
def P2(s):
    ctr = 0
    for i in range(1,len(s)):
        if s[i] != s[i-1]:
            ctr += 1
    if s[-1] == '-':
        ctr += 1
    return ctr


inp_filename = r"F:\Nir\Downloads\B-large.in"
out_filename = r"F:\Nir\Downloads\GCJ\res.out"

f = open(inp_filename, 'r')
st = f.read()
l = st.split('\n')
ou = open(out_filename, 'w')

t = int(l[0])
for i in range(1,t+1):
    ou.write("Case #{0}: ".format(i) + str(P2(l[i]))+"\n")

f.close()
ou.close()