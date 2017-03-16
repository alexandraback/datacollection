from collections import Counter, defaultdict

uniqs = [
    [('Z', Counter('ZERO'), '0'),
     ('X', Counter('SIX'), '6'),
     ('W', Counter('TWO'), '2'),
     ('U', Counter('FOUR'), '4'),
     ('G', Counter('EIGHT'), '8')],
    [('T', Counter('THREE'), '3'),
     ('S', Counter('SEVEN'), '7'),
     ('O', Counter('ONE'), '1'),
     ('F', Counter('FIVE'), '5')]
]

def go2(s):
    cnt_s = Counter(s)
    n_s = len(s)
    result = ''
    for uniq in uniqs:
        for letter, lset, num in uniq:
            how_many = cnt_s[letter]
            if how_many > 0:
                for k in lset:
                    cnt_s[k] -= how_many * lset[k]
                n_s -= how_many * sum(lset.values())
                result += num * how_many
    if n_s > 0:
        result += (n_s/4) * '9'
    return ''.join(sorted(result))

n = int(raw_input())
# for case in [
# 'VOEZWSININENINENSREXEOT'
# 'OZONETOWER',
# 'WEIGHFOXTOURIST',
# 'OURNEONFOE',
# 'ETHER',
# ]:
for i in range(n):
    case = raw_input().strip()
    print 'Case #%d: %s' % (i+1, go2(case))
    # print go2(case)
