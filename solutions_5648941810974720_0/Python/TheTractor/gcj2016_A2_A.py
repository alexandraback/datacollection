#!/usr/bin/env python

"""
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
Count Z => ZERO count
"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
Count W => TWO count
"ONE", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
Count X => SIX count
"ONE", "THREE", "FOUR", "FIVE", "SEVEN", "EIGHT", "NINE"
Count U => FOUR count
"ONE", "THREE",  "FIVE", "SEVEN", "EIGHT", "NINE"
Count S => SEVEN count
"ONE", "THREE",  "FIVE", "EIGHT", "NINE"
Count O => ONE count
"THREE",  "FIVE", "EIGHT", "NINE"
Count R => THREE count
"FIVE", "EIGHT", "NINE"
Count H => EIGHT count
Count F => FIVE count
Count E => NINE count
"""

strategy = ((0, "Z", "ZERO"), (2, "W", "TWO"), (6, "X", "SIX"), (4, "U", "FOUR"), 
       (7, "S", "SEVEN"), (1, "O", "ONE"), (3, "R", "THREE"), (8, "H", "EIGHT"),
       (5, "F", "FIVE"), (9, "E", "NINE"))

test_cases = int(raw_input())
for counter in xrange(1, test_cases+1):
    word = [k for k in raw_input()]
    counters = {}
    
    for letter in word:
        counters[letter] = counters.get(letter, 0) + 1
       
    values = []
    for (value, indicator, letters) in strategy:
        count = counters.get(indicator,0)
        if count > 0:
            values += [value] * count
            for letter in letters:
                counters[letter] -= count
            #print indicator, counters
    
    #if min(counters.values()) < 0 or max(counters.values()) > 0:
    #   print word, values
    #   break
       
    #print max(counters.values()), min(counters.values())
    
    values.sort()
    print 'Case #%d: %s' % (counter, ''.join(str(k) for k in values))