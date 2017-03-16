import string

trans = string.maketrans('abcdefghijklmnopqrstuvwxyz','yhesocvxduiglbkrztnwjpfmaq')

ofile = open('out.txt','w')

with open ('inp.txt') as f:
    count = 0
    nline = 0
    for line in f:
        if count == 0:
            nline = int(line)
            count += 1
            continue
        ofile.write('Case #'+str(count)+': '+line.translate(trans))
        count += 1
        if count == (nline+1):
            break

ofile.close()

