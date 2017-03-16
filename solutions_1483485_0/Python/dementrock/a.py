def main():
    dic = {'q': 'z', 'z': 'q', 'a': 'y', 'o': 'e'}

    def learn(code, origin):
        for i in range(len(code)):
            dic[code[i]] = origin[i]

    learn("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand")
    learn("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities")
    learn("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up")

    def translate(s):
        return ''.join(map(lambda x: dic[x], list(s)))

    t = int(raw_input())
    for i in range(t):
        s = raw_input()
        print "Case #%d: %s" % (i + 1, translate(s))


if __name__ == "__main__":
    main()

