import math

def is_palindrome(string):
    i = 0
    while i < len(string) / 2 + 1:
        if string[i] != string[-1-i]:
            return False
        i += 1
    return True

# Newton's method for integers,
# http://math.stackexchange.com/questions/41337/efficient-way-to-determine-if-a-number-is-perfect-square
def get_root(integ):
    xold = 0
    x = long(math.sqrt(integ))
    while(x - xold > 0):
        xold = x
        x = (x**2 + integ) / (2 * x)
    return x

def make_palindrome(integ, increment):
    tmp = list(str(integ))
    middle = (len(tmp) - 1) / 2
    if increment:
        tmp_i = middle
        while tmp_i >= 0 and tmp[tmp_i] == '9':
            tmp_i -= 1
        if tmp_i < 0:
            return '1' + '0' * (len(tmp) - 1) + '1'
        # else:
        tmp[tmp_i] = str(int(tmp[tmp_i]) + 1)
        tmp_i += 1
        while tmp_i <= middle:
            tmp[tmp_i] = '0'
            tmp_i += 1
    # both increment and no increment:
    i = middle
    while i >= 0:
        tmp[-1 - i] = tmp[i]
        i -= 1
    return ''.join(tmp)

def get_next_palindrome(integ):
    tmp = str(integ)
    middle = (len(tmp) - 1) / 2
    i = middle
    while i >= 0:
        if int(tmp[-1-i]) > int(tmp[i]):
            # then must increment middle value
            return make_palindrome(integ, True)
        i -= 1
    return make_palindrome(integ, False)

def is_fns(small, large):
    start = get_root(small)
    start = start if (start ** 2 >= small) else start + 1
    current = long(get_next_palindrome(start))
    count = 0
    limit = get_root(large)
    while current <= limit:
        if is_palindrome(str(current ** 2)):
            count += 1
        current = long(get_next_palindrome(current + 1))
    return count

cases = int(raw_input())
for c in xrange(cases):
    small, large = map(long, raw_input().split())
    print "Case #%d: %s" % ((c+1), is_fns(small, large))
    
