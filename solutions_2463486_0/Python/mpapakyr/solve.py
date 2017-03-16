#! /usr/bin/python

import os, sys, math

T = int(sys.stdin.readline())


def isodd(i):
    return i & 1 and True or False

def check_palindrome_sqrt(number, A, B):
    #print 'checking number %s' % number
    sq = number**2
    sq_str = str(sq)
    l = len(sq_str)
    #print '######    sq = %s' % sq_str
    #print '######    sq = %s' % sq_str[::-1]
    for i in range(0, l):
        rev = l-i-1
        if sq_str[i] <> sq_str[rev]:
            #print '######  return False (i=%s,r=%s,v1=%s,v2=%s)' % (i,rev, sq_str[0], sq_str[rev])
            return False
    #print '######  return True'
    return sq >= A and sq <= B

def solve_almost_brute(A, B):
    start = int(math.ceil(math.sqrt(A)))
    end = int(math.floor(math.sqrt(B)))
    start_digit_count = len(str(start))
    end_digit_count = len(str(end))
    result = []

    #print 'A=%s, B=%s, start = %s, end = %s. start_count = %s. end_count =%s' % (
    #    A, B, start, end, start_digit_count, end_digit_count)

    if start > end:
        return result
    
    for i in range(start_digit_count, end_digit_count+1):
        #print '# iterating on %i digit numbers' % i
        if isodd(i):
            digits = (i - 1) / 2
            add_one_more = True
        else:
            digits = i / 2
            add_one_more = False
        #print 'i = %s' % i
        
        if i == 1:
            for number in range(0,10):
                #print '@@ one digit : %s' % number
                if check_palindrome_sqrt(number, A, B):
                    result.append(number)

        num_right_start = 0
        num_right_end = 10**digits
        for right in range(num_right_start, num_right_end):
            #print '## i = %s, d = %s, right = %s' % (i, digits, right)
            #print '#### right number is  = %s' % right
            left = str(right)[::-1]
            if left[0] == '0': continue
            elif add_one_more:
                number = 0
                for m in range(0,10):
                    fix_length = digits - len(left)
                    left_int = int(left)*(10**(i-digits+fix_length))
                    middle_int = m*(10**(i - digits - 1))
                    #print '@@ odd with middle:'
                    #print 'left %s' % left_int
                    #print 'middle %s' % middle_int
                    #print 'right  %s' % right                    
                    number = int(left_int + middle_int  + right)
                    if number < start:
                        continue
                    if number > end:
                        continue
                    if i == 11:
                        #sys.stdout.write('%s ' % number)
                        pass
                    #print number
                    if check_palindrome_sqrt(number, A, B):
                        if i == 11: 
                            #sys.stdout.write(' YES\n')
                            pass
                        result.append(number)
                    else:
                        if i == 11: 
                            #sys.stdout.write(' NO\n')
                            pass
                if number > end:
                    continue
            else:
                fix_length = digits - len(left)
                left_int = int(left)*(10**(i-digits+fix_length))
                number = int(left_int + right)
                #print '@@ even'
                #print 'left (i=%s, d=%s) = %s' % (i, digits, left)
                #print 'right = %s' % right
                #print number
                if i == 10:
                    #sys.stdout.write('%s ' % number)
                    pass
                if number > end:
                    continue
                if number < start:
                    continue
                if check_palindrome_sqrt(number, A, B):
                    if i == 10: 
                        #sys.stdout.write(' YES\n')
                        pass
                    result.append(number)
                else:
                    if i == 10:
                        #sys.stdout.write(' NO\n')
                        pass

    return result

result_all = solve_almost_brute(1, 10**14)

for t in range(1, T+1):
    line = sys.stdin.readline().split(' ')
    A = int(line[0])
    B = int(line[1])
    result = [x for x in result_all if x**2 >= A and x**2 <= B]
    #sys.stdout.write('Case #%s: %s\n' %(t, ' '.join([str(x) for x in result])))
    sys.stdout.write('Case #%s: %s\n' %(t, len(result)))
