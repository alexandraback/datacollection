from toolz import *

def read_int():
    return int(raw_input())

def solve(s):
    char_freq = {i: 0 for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'}
    for i in s:
        char_freq[i] += 1
    digit_freq = {}
    digit_freq[0] = char_freq['Z']
    digit_freq[8] = char_freq['G']
    digit_freq[6] = char_freq['X']
    digit_freq[2] = char_freq['W']
    digit_freq[4] = char_freq['U']
    digit_freq[3] = char_freq['H'] - digit_freq[8]
    digit_freq[7] = char_freq['S'] - digit_freq[6]
    digit_freq[5] = char_freq['V'] - digit_freq[7]
    digit_freq[9] = char_freq['I'] - digit_freq[5] - digit_freq[6] - digit_freq[8]
    digit_freq[1] = char_freq['O'] - digit_freq[0] - digit_freq[2] - digit_freq[4]

    return ''.join([chr(i + ord('0')) * digit_freq[i] for i in range(10)])
            
for case in range(read_int()):
    S = raw_input()
    ans = solve(S)
    print "Case #%d: %s" % (case+1, ans)
