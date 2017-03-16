import sys

table = {}
samples = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi":
        "our language is impossible to understand",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd":
        "there are twenty six factorial possibilities",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv":
        "so it is okay if you want to just give up",
    "yeq": "aoz",
    "z": "q",
}

def gen_conv_table(source, dest):
    ret = {}
    for i in range(len(source)):
        ret[source[i]] = dest[i]

    return ret

[table.update(gen_conv_table(a, b)) for a, b in samples.items()]

def convert(text):
    return ''.join([table[x] for x in text])

def solve(input):
    return convert(input)

def run():
    cases = int(sys.stdin.readline().strip())
    for i in range(cases):
        print("Case #{}: {}".format(i + 1, solve(sys.stdin.readline().strip())))

if __name__ == "__main__":
    run()

