# convert from googlese to english
def cipher(letter):
    # we will construct a lookup table using the example text.
    lookup = dict()
    ptext = ["a", "o", "z", "q", 
             "our language is impossible to understand", 
             "there are twenty six factorial possibilities",
             "so it is okay if you want to just give up"]
    ctext = ["y", "e", "q", "z",
             "ejp mysljylc kd kxveddknmc re jsicpdrysi",
             "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
             "de kr kd eoya kw aej tysr re ujdr lkgc jv"]
    examples = zip(ptext, ctext)
    for example in examples:
        ptext, ctext = example
        pairs = zip(ptext, ctext)
        for pair in pairs:
            p, c = pair
            lookup[c] = p
    return lookup[letter]

# grab number of cases
cases = int(raw_input())

# array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    ctext = raw_input()
    inputs.append((ncase,ctext))

# calculate answer
for case in inputs:
    ncase, ctext = case
    ptext = ""
    for char in ctext:
        ptext += cipher(char) 
    print "Case #" + str(ncase + 1) + ": " + ptext
