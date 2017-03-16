googlerese = 'ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvzq'
english    = 'our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upqz'

t = int(input())
for i in range(1,t+1):
    print('Case #' + str(i) + ':', end=' ')
    for c in input():
        if googlerese.find(c) == -1: print('oh noes!!')
        print(english[googlerese.find(c)], end='')
    print()
