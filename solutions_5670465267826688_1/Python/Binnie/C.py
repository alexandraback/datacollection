import sys

MAX_POSSIBLE_SCORE = 10**32

times = {
    ('i', 'i'): '-1',
    ('i', 'j'): 'k',
    ('i', 'k'): '-j',
    ('i', '-i'): '1',
    ('i', '-j'): '-k',
    ('i', '-k'): 'j',
    ('i', '1'): 'i',
    ('i', '-1'): '-i',
    ('-i', 'i'): '1',
    ('-i', 'j'): '-k',
    ('-i', 'k'): 'j',
    ('-i', '-i'): '-1',
    ('-i', '-j'): 'k',
    ('-i', '-k'): '-j',
    ('-i', '1'): '-i',
    ('-i', '-1'): 'i',
    ('j', 'i'): '-k',
    ('j', 'j'): '-1',
    ('j', 'k'): 'i',
    ('j', '-i'): 'k',
    ('j', '-j'): '1',
    ('j', '-k'): '-i',
    ('j', '1'): 'j',
    ('j', '-1'): '-j',
    ('-j', 'i'): 'k',
    ('-j', 'j'): '1',
    ('-j', 'k'): '-i',
    ('-j', '-i'): '-k',
    ('-j', '-j'): '-1',
    ('-j', '-k'): 'i',
    ('-j', '1'): '-j',
    ('-j', '-1'): 'j',
    ('k', 'i'): 'j',
    ('k', 'j'): '-i',
    ('k', 'k'): '-1',
    ('k', '-i'): '-j',
    ('k', '-j'): 'i',
    ('k', '-k'): '1',
    ('k', '1'): 'k',
    ('k', '-1'): '-k',
    ('-k', 'i'): '-j',
    ('-k', 'j'): 'i',
    ('-k', 'k'): '1',
    ('-k', '-i'): 'j',
    ('-k', '-j'): '-i',
    ('-k', '-k'): '-1',
    ('-k', '1'): '-k',
    ('-k', '-1'): 'k',
    ('1', 'i'): 'i',
    ('1', 'j'): 'j',
    ('1', 'k'): 'k',
    ('1', '-i'): '-i',
    ('1', '-j'): '-j',
    ('1', '-k'): '-k',
    ('1', '1'): '1',
    ('1', '-1'): '-1',
    ('-1', 'i'): '-i',
    ('-1', 'j'): '-j',
    ('-1', 'k'): '-k',
    ('-1', '-i'): 'i',
    ('-1', '-j'): 'j',
    ('-1', '-k'): 'k',
    ('-1', '1'): '-1',
    ('-1', '-1'): '1',
}


def multiply(x, y):
    return times[(x, y)]


def find_overall_value(chars):
    cur_val = '1'
    for char in chars:
        cur_val = multiply(cur_val, char)
    return cur_val


def find_best_i(x, chars, all_chars_value):
    best_score = MAX_POSSIBLE_SCORE
    cur_val = '1'
    for ii in range(len(chars)):
        char = chars[ii]
        cur_val = multiply(cur_val, char)

        cur_multiplier_val = cur_val
        for jj in range(min(x, 4)):
            if cur_multiplier_val == 'i':
                best_score = min(best_score, ii + jj * len(chars))
            cur_multiplier_val = multiply(all_chars_value, cur_multiplier_val)

    return best_score + 1


def find_best_k(x, l, chars, all_chars_value):
    best_score = MAX_POSSIBLE_SCORE
    cur_val = '1'
    for ii in range(l):
        char = chars[l-1-ii]
        cur_val = multiply(char, cur_val)

        cur_multiplier_val = cur_val
        for jj in range(min(x, 4)):
            if cur_multiplier_val == 'k':
                best_score = min(best_score, ii + jj * l)
            cur_multiplier_val = multiply(cur_multiplier_val, all_chars_value)

    return best_score + 1


def is_a_j(x, l, chars, num_chars_for_i, num_chars_for_k):
    num_overall_used_for_i = num_chars_for_i
    num_overall_used_for_k = num_chars_for_k
    num_chars_remaining = x*l - num_overall_used_for_i - num_overall_used_for_k
    if num_chars_remaining <= 0:
        return False
    num_chars_remaining = (num_chars_remaining % (4 * l))
    cur_val = '1'
    for ii in range(num_chars_remaining):
        char = chars[(num_chars_for_i + ii) % l]
        cur_val = multiply(cur_val, char)

    return cur_val == 'j'

f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    L, X = map(int, f.readline().strip().split())
    string = f.readline().strip()

    all_chars_value = find_overall_value(string)

    best_i = find_best_i(X, string, all_chars_value)
    best_k = find_best_k(X, L, string, all_chars_value)

    print "Case #%d: " % (test + 1), "YES" if is_a_j(X, L, string, best_i, best_k) else "NO"