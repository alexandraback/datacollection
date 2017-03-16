import sys

char_map = {
    'y' : 'a',
    'e' : 'o',
    'q' : 'z'
}

sample_input = """ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"""
sample_output = """our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"""


for k, v in zip(sample_input, sample_output):
    char_map[k] = v

char_map['z'] = 'q'

T = int(sys.stdin.readline())
result = []
for i in range(T):
    result.append("".join([char_map.get(k, k) for k in sys.stdin.readline().strip()]))

for i, v in enumerate(result):
    print "Case #%d: %s" % (i+1, v)
