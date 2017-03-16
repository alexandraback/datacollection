#!/usr/bin/python
# -*- coding: utf-8 -*-

def main():
    in_file = open("A-small-attempt1.in", mode='r')
    out_file = open("A-small-attempt1.out", mode='w')

    lines = in_file.readlines()      
    T = int(lines[0])
    
    for i in xrange(T):
        S = lines[i + 1]

        letters = [0] * 26
        digits = [0] * 10
        
        digits_info = (
            (0, 'ZERO', ord('Z') - ord('A')), 
            (2, 'TWO', ord('W') - ord('A')), 
            (6, 'SIX', ord('X') - ord('A')), 
            (8, 'EIGHT', ord('G') - ord('A')), 
            (3, 'THREE', ord('T') - ord('A')), 
            (4, 'FOUR', ord('R') - ord('A')), 
            (1, 'ONE', ord('O') - ord('A')), 
            (5, 'FIVE', ord('F') - ord('A')), 
            (7, 'SEVEN', ord('S') - ord('A')), 
            (9, 'NINE', ord('I') - ord('A')), 
        )        
        
        for c in S[:-1]:
            idx = ord(c) - ord('A')
            letters[idx] = letters[idx] + 1

        for d in digits_info:
            d_cnt = letters[d[2]]
            digits[d[0]] = d_cnt
            for c in d[1]:
                idx = ord(c) - ord('A')
                letters[idx] = letters[idx] - d_cnt
        
        out_file.write("Case #" + str(i+1) + ": ") 
        for d, c in enumerate(digits):
            if c>0:
                out_file.write(''.join([str(d)]*c)) 
        out_file.write("\n") 
        
    in_file.close()
    out_file.close()


if __name__ == '__main__':
    main()
