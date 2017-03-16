import sys

translate_table = {}

translate_table['a'] = 'y'
translate_table['b'] = 'h'
translate_table['c'] = 'e'
translate_table['d'] = 's'
translate_table['e'] = 'o'
translate_table['f'] = 'c'
translate_table['g'] = 'v'
translate_table['h'] = 'x'
translate_table['i'] = 'd'
translate_table['j'] = 'u'
translate_table['k'] = 'i'
translate_table['l'] = 'g'
translate_table['m'] = 'l'
translate_table['n'] = 'b'
translate_table['o'] = 'k'
translate_table['p'] = 'r'
translate_table['q'] = 'z'
translate_table['r'] = 't'
translate_table['s'] = 'n'
translate_table['t'] = 'w'
translate_table['u'] = 'j'
translate_table['v'] = 'p'
translate_table['w'] = 'f'
translate_table['x'] = 'm'
translate_table['y'] = 'a'
translate_table['z'] = 'q'


white_spaces = [' ', '\t', '\n']

num_cases = int( sys.stdin.readline() )
for case in range( 1, num_cases+1 ):
    line = sys.stdin.readline()
    line = line.strip()
    out_line = ''
    for c in line:
        if c not in white_spaces:
            out_line += translate_table[c]
        else:
            out_line += c
    print "Case #%s: %s" % (case, out_line)

    
    
