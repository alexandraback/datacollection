import sys

ans = [i for i in open(sys.argv[2])]
mapping = {'q':'z', 'z':'q'}

for i,case in enumerate(open(sys.argv[1])):
    if i == 0: continue #drop first line
    
    case = case.strip()
    for j,c in enumerate(case):
        mapping[c] = ans[i-1][j]
    
#for i in "abcdefghijklmnopqrstuvwxyz":
#    print(i, mapping.get(i, "none"))

result = []
for i,case in enumerate(open(sys.argv[3])):
    if i == 0: continue #drop first line
    
    case = case.strip()
    a = map(lambda x: mapping[x], case)    
    result.append("Case #%d: %s" % (i, ''.join(list(a))))

f = open("out",'w')
f.write('\n'.join(result))