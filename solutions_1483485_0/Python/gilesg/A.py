from string import lowercase

INPUT = """
y e q
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
""".split()

OUTPUT = """
a o z
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
""".split()

d = {}

for in_word, out_word in zip(INPUT, OUTPUT):
    for x, y in zip(in_word, out_word):
        if x in d and d[x] != y:
            print "FAIL"
            quit()
        d[x] = y

input_remaining = set(lowercase).difference(set(d.keys()))
output_remaining = set(lowercase).difference(set(d.values()))

assert len(input_remaining) == 1
assert len(output_remaining) == 1

d[list(input_remaining)[0]] = list(output_remaining)[0]

d[' '] = ' '

T = int(raw_input())

for case_num in xrange(1, T+1):
    res = ''.join(d[c] for c in raw_input())
    print "Case #%d: %s" % (case_num, res)
