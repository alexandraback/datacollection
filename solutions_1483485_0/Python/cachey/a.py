import string

leet = string.maketrans("yqeeejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvz", "azooour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upq")
print leet
foo = file("a.out", "w")
bar = file("a.in", "r")

a = int(bar.readline())

for i in xrange(0, a):
	b = bar.readline()
	foo.write("Case #" + str(i+1) + ": " + b.translate(leet))
