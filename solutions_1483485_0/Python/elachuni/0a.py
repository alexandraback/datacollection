f = open('A-small-attempt0.in')

null = ''.join(chr(x) for x in range(256))
                #~ 'abcdefghijklmnopqrstuvwxyz'
code = null[:97] + 'yhesocvxduiglbkrztnwjpfmaq' + null[123:]

T = int(f.readline().strip())
for i in range(T):
    case = f.readline().strip('\n')
    print 'Case #%d: %s' % (i + 1, case.translate(code))
