from collections import defaultdict

import fileinput 

round_one_words = ("ZERO", #Z
                   "ONE",
                   "TWO", #W
                   "THREE",
                   "FOUR", #U
                   "FIVE",
                   "SIX", #X
                   "SEVEN",
                   "EIGHT", #G
                   "NINE")

round_two_words = ("ONE", #O
                   "THREE", #T
                   "FIVE", #F
                   "SEVEN", #S
                   "NINE")

def find_unique(words):
    for w in words:
        for l in w:
            not_found = True
            for x in words:
                if x == w:
                    continue
                if l in x:
                    not_found = False
                    break
            if not_found:
                print w,l

#find_unique(round_two_words)

def count_letters(s):
    counter = defaultdict(int)
    for l in s:
        counter[l] += 1
    return counter

round_one_words = ("ZERO", #Z
                   "ONE",
                   "TWO", #W
                   "THREE",
                   "FOUR", #U
                   "FIVE",
                   "SIX", #X
                   "SEVEN",
                   "EIGHT", #G
                   "NINE")

round_two_words = ("ONE", #O
                   "THREE", #T
                   "FIVE", #F
                   "SEVEN", #S
                   "NINE")


extract_map = [("Z",("ZERO","0")),
                 ("W",("TWO", "2")),
                 ("U",("FOUR","4")),
                 ("X",("SIX","6")),
                 ("G",("EIGHT","8")),
#part2
               ("O",("ONE","1")),
               ("T",("THREE","3")),
               ("F",("FIVE","5")),
               ("S",("SEVEN","7")),
#part3
               ( "I",("NINE","9"))
]

def extract_digits(counts,m,s):
    digits = []
    for k,v in m:
        num_rep = counts[k]
        digits += [v[1]]*num_rep
        for l in v[0]:
            counts[l] -= num_rep
            if counts[l] < 0:
                print "Badness:",l,s,counts,digits
            assert counts[l] >= 0
    return (digits,counts)

def solve(s):
    counts = count_letters(s)
    digits,counts = extract_digits(counts,extract_map,s)
    for v in counts.values():
        if v != 0:
            print "BADNESS!"
            print s,counts
    return "".join(sorted(digits))

def main():
    it = fileinput.input()
    cnt = it.next()
    for i,l in enumerate(it,1):
        print "Case #%d: %s" % (i,solve(l.strip()))

if __name__ == "__main__":
    main()
