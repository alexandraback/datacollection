'''
Created on May 12, 2013

@author: uglytroll
'''

def is_consecutive(subword):
    if 'a' in subword or 'e' in subword or 'i' in subword or 'o' in subword or 'u' in subword:
        return False
    return True

def get_consecutive(word, n):
    n = int(n)
#     print 'got word : %s, n : %s' % (word, n)
    for start in xrange(len(word) - n + 1):
#         print 'checking : %s' % word[start: start + n]
        if is_consecutive(word[start: start + n]):
#             print 'got consecutive : %s' % word[start: start + n]
            yield (start, start + n)

def n_value(word, n):
#     print 'read word : %s, n : %s' % (word, n)
    pre_start = 0
    result = 0
    for (start, end) in get_consecutive(word, n):
        after_count = len(word) - end + 1
        before_count = start - pre_start
#         print 'after : %s, before :%s' % (after_count, before_count)
        result += (after_count * before_count) + after_count
        pre_start = start + 1
    return result

f = open('/home/uglytroll/codejam/2013/1c/A-large.in', 'r')
o = open('/home/uglytroll/codejam/2013/1c/A-large.out', 'w')

T = int(f.readline().strip())

for t in xrange(T):
    (word, n) = f.readline().strip().split(' ')
    result = n_value(word, n)
    s = "Case #%d: %s\n" % (t+1, result)
#     print s
    o.write(s)
    