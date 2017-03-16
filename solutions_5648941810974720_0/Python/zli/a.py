from collections import Counter
numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def unique_letters():
    snumbers = set(numbers)
    found = True
    uniques = []
    while found:
        found = False
        for number in list(snumbers):
            unique = [c for c in number if
                      all(c not in other
                          for other in snumbers - set([number]))]
            if unique:
                #print number, unique
                uniques.append((numbers.index(number), unique[0], Counter(number)[unique[0]]))
                snumbers -= set([number])
                found = True
    return uniques

uniques = unique_letters()
for case in range(1, input()+1):
    print "Case #%s:" % (case),
    S = raw_input()
    letter_counts = Counter(S)
    number_counts = {}
    #print letter_counts
    for number, unique, mult in uniques:
        count = letter_counts[unique] / mult
        number_counts[number] = count
        for letter in numbers[number]:
            letter_counts[letter] -= count
    #print number_counts
    #print letter_counts
    if not min(letter_counts.values()) == max(letter_counts.values()) == 0:
        raise Exception("Non-zero final count!")
    print "".join(str(number)*number_counts[number] for number in range(10))
        
