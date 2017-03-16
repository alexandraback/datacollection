txt_goog = 'ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv'
txt_eng = 'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up'

goog = []
eng = []

for i in range(len(txt_goog)):
    if txt_goog[i] != ' ':
        if not txt_goog[i] in goog:
            goog.append(txt_goog[i])
            eng.append(txt_eng[i])

goog.append('z')
goog.append('q')

eng.append('q')
eng.append('z')

inp = open('A-small-attempt0.in', 'r')
out = open('output.txt', 'w')

n = int(inp.readline())
for i in range(n):
    si = inp.readline()
    so = ''
    for j in range(len(si)):
        if si[j] == ' ':
            so = so + ' '
        else:
            for k in range(len(goog)):
                if si[j] == goog[k]:
                    so = so + eng[k]
                    break

    out.writelines('Case #' + str(i+1) + ': ' + so + '\n')

inp.close()
out.close()
