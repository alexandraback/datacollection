import string

source = 'abcdefghijklmnopqrstuvwxyz'
dest =   'yhesocvxduiglbkrztnwjpfmaq'

table = string.maketrans(source, dest)

num_lines = int(raw_input(''))
lines = list()
for i in range(num_lines):
    lines.append(raw_input(''))

for case, line in enumerate(lines):
    print "Case #{0}: {1}".format(case+1, line.translate(table))

