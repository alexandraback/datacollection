from collections import Counter

nums = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']

def result(input):
    input = Counter(input)
    out = [0]*10

    out[0] = input['Z']
    remove(input, 'ZERO', input['Z'])
    out[6] = input['X']
    remove(input, 'SIX', input['X'])
    out[2] = input['W']
    remove(input, 'TWO', input['W'])
    out[4] = input['U']
    remove(input, 'FOUR', input['U'])
    out[8] = input['G']
    remove(input, 'EIGHT', input['G'])
    out[3] = input['T']
    remove(input, 'THREE', input['T'])
    out[7] = input['S']
    remove(input, 'SEVEN', input['S'])
    out[1] = input['O']
    remove(input, 'ONE', input['O'])
    out[5] = input['F']
    remove(input, 'FIVE', input['F'])
    out[9] = input['I']
    remove(input, 'NINE', input['I'])
    print(input)
    s = ''
    for i in range(10):
        s += str(i)*out[i]
    return s
                        
def remove(input, num, mult):
    for i in num:
        input[i] -= mult



f = open('A-small-attempt1.in')
r = f.readlines()
w = open('A-small-attempt1.out','w')

for i,line in enumerate(r[1:]):
    w.write('Case #%s: %s\n' % (str(i+1), result(line.strip())))
f.close()
w.close()

# zero z, six x, two w, four u, eight g
# three t, seven s, one o, five f
# nine