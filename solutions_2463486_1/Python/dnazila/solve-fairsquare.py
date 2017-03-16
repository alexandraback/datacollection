import sys
import math
#should handle different length numbers

fname = sys.argv[1]

f = open(fname, "rt")

T = int(f.readline())

def int_sqrt(x): #borrowed
    n = long(x)
    if n == 0:
        return 0
    a,b = divmod(n.bit_length(), 2)
    x = 2 ** (a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y


def is_palindrome(n):
    ns = str(n)
    for i in range((len(ns) + 1) / 2):
        if ns[i] != ns[-1-i]:
            return False

    #print "number is %d:%d" % (math.sqrt(n), n)
    return True

def incorrect(cur_num_digs, dignum, curdig, end):
    for i in range(curdig+1, dignum):
        cur_num_digs[i] = 0
    for i in range(curdig+1):
        cur_num_digs[dignum-i-1] = cur_num_digs[i]

    #print "lll", cur_num_digs, dignum, curdig
    n = long("".join(map(str, cur_num_digs)))
    if n > end:
        return True

    n2 = n ** 2 

    return not is_palindrome(n2)

#    cur_num_digs[curdig:dignum] = [0 for i in range(curdig, dignum)]
#
#   
#    #digits are the pivit point 
#    for i in range(curdig+1):
#        total = 0
#        for j in range(i+1):
#            total += cur_num_digs[i-j] * cur_num_digs[i+j]
#        if total >= 10:
#            return True
#
#    #spaces between digits are the pivots
#    for i in range(curdig):
#        total = 0
#        for j in range(i+1):
#            total += cur_num_digs[i-j] * cur_num_digs[i+j]
#        if total >= 10:
#            return True
#
#    return False



def same_len(cur_num_digs, start, end, start_digs, end_digs, dignum, curdig, already_less_than_max, already_greater_than_min):
    #print "same_len start=%d end=%d curdig=%d cur_num_digs=%s dignum=%d"%( start, end, curdig, cur_num_digs, dignum)
    total = 0
    #print "here", long("".join([str(x) for x in cur_num_digs])), cur_num_digs, curdig
    if (curdig  == (dignum+1) / 2):
        if (already_greater_than_min or long("".join([str(x) for x in cur_num_digs])) >= start):# if the curdig is the one after the middle
            #print "found one!!!", cur_num_digs
            return 1
        else:
            return 0
    for d in [0, 1, 2, 3]:
        #print curdig
        #print cur_num_digs
        if curdig == 0 and d == 0:
            continue
        #print "d=%d" % d
        #print "here"
        #print 
        #print curdig, cur_num_digs
        #print cur_num_digs[curdig]
        cur_num_digs[curdig] = d
        if already_greater_than_min or d >= start_digs[curdig]:
            new_agtm = already_greater_than_min or d > start_digs[curdig]
            if already_less_than_max or d <= end_digs[curdig]:
                new_altm = already_less_than_max or d < end_digs[curdig]
                if incorrect(cur_num_digs, dignum, curdig, end):
                    continue
                else:
                    total += same_len(cur_num_digs, start, end, start_digs, end_digs, dignum, curdig+1, new_altm, new_agtm)


    return total
                    



def handle_case(f, caseno):
    line = f.readline()
    vals = line.split()
    start = long(vals[0])
    end = long(vals[1])
    start_sqrt = int_sqrt(start)
    if start_sqrt ** 2 < start:
        start_sqrt += 1
    end_sqrt = int_sqrt(end)

    start_digit = len(str(start_sqrt))
    end_digit = len(str(end_sqrt))

    total = 0
    for dig in range(start_digit, end_digit+1):
        start = long("1" + "0" * (dig - 1))
        end = long("9" * dig)
        if dig == start_digit:
            start = start_sqrt
        if dig == end_digit:
            end = end_sqrt
        start_digs = [int(c) for c in str(start)]
        end_digs = [int(c) for c in str(end)]
        dignum = len(str(start))
        cur_num_digs = [x for x in start_digs]
        total += same_len(cur_num_digs, start, end, start_digs, end_digs, dig, 0, False, False)
    print "Case #%d: %d"%(caseno, total)
    #count = 0
    #for x in range(start_sqrt, end_sqrt+1):
    #    if is_palindrome(x) and is_palindrome(x**2):
    #        count += 1

    #if count != total:
    #    print "bug:", caseno, total, ":", count



        

for case in range(T):
    handle_case(f, case+1)
        

    
