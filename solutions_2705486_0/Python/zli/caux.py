import pickle

words = open("garbled_email_dictionary.txt").read().split("\n")
"""
wdict = [defaultdict(lambda:[]) for i in xrange(11)]
for w in words:
    print w
    for i,c in enumerate(w):
        letters = list(w)
        letters[i] = "*"
        wdict[len(w)]["".join(letters)].append(w)
plainwdict = map(dict,wdict)
"""

wdict = defaultdict(list)
for w in words:
    print w
    for i,c in enumerate(w[:5]):
        letters = list(w[:5])
        letters[i] = "*"
        wdict["".join(letters)].append(w)
ddwdict = wdict
plainwdict = dict(wdict)

pickle.dump(plainwdict,open("wdict.pkl","w"))
