from __future__ import division
import sys
import numpy as np

def palindromes(begin):
    str_begin = str(begin)
    num_digits = len(str_begin)
    hlf_num = int(str_begin[:int(np.ceil(num_digits/2))])-1
    len_hlf_num = int(np.ceil(num_digits/2))
    border = 10**len_hlf_num

    while True:
        hlf_num+=1
        if hlf_num >= border:
            num_digits+=1
            len_hlf_num = int(np.ceil(num_digits/2))
            hlf_num = int(str(hlf_num)[:int(np.ceil(num_digits/2))])
            border = 10**len_hlf_num

        if num_digits%2 == 0:
            #even
            str_hlf_num = str(hlf_num)
            str_full_num = str_hlf_num + str_hlf_num[-1::-1]
        else:
            str_hlf_num = str(hlf_num)
            str_full_num = str_hlf_num + str_hlf_num[-2::-1]
        full_num = int(str_full_num)
        yield full_num

def is_palindrome(num):
    str_num = str(num)
    i = 0
    j = len(str_num)-1
    while i < j:
        if str_num[i] != str_num[j]:
            return False
        i+=1
        j-=1
    return True

def solve(begin, end):
    count = 0
    for pl in palindromes(int(np.ceil(np.sqrt(begin)))):
        sqr_pl = pl**2
        if sqr_pl < begin:
            continue
        elif sqr_pl > end:
            break
        if is_palindrome(sqr_pl):
            count+=1
    return count

if __name__ == '__main__':
    fh = open(sys.argv[1])
    T = int(fh.readline().strip())
    for ii in xrange(1,T+1):
        begin, end = [int(v) for v in fh.readline().strip().split()]
        output = solve(begin, end)
        print "Case #{}: {}".format(ii, output)





