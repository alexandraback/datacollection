fi = open('small.in')
fi = open('small2.in')
fi = open('B-large.in', 'r')
fo = open('bresult.out', 'w')

T = int(fi.readline())

def count_change(S):
    last_char = S[0]
    num_of_changes = 0
    for s in S[1:]:
        if s != last_char:
            num_of_changes += 1
        last_char = s
    return num_of_changes

for t in range(1, T+1):
    S = fi.readline().strip()

    additional_flip = 0
    if S[-1] == '-':
        # print "+1"
        additional_flip = 1 # when the most bottom pancake is '-' (or not done)
    output_val = count_change(S) + additional_flip
    print output_val
    fo.write('Case #%i: %i\n' % (t, output_val))