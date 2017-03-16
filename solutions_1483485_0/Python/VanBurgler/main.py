import string

f = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z"
t = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q"

mapping = dict(zip(list(f), list(t)))

n = input()

for i in range(1, int(n) + 1):
	string = input()
	result = list(map((lambda x: mapping.get(x)), string))
	print('Case #{}: {}'.format(i, ''.join(result)))