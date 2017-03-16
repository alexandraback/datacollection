line1 = "abcdefghijklmnopqrstuvwxyz"
line2 = "yhesocvxduiglbkrztnwjpfmaq"
M = dict()
M[' '] = ' '
for i in range(26):
    M[line1[i]] = line2[i]

T = int(raw_input());
for i in range(T):
    line = raw_input();
    line = reduce(str.__add__, [M[c] for c in line], "")
    print "Case #%d: %s" %(i+1, line)

