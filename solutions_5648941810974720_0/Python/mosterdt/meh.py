#!/usr/bin/env python2

numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

19


def case(T):
    test = raw_input()
    #print "".join(test)
    backup = test[:]
    answer = ""
    blech = [('0', 'Z'), ('2', 'W'), ('6', 'X'), ('8', 'G'), ('3', 'T'), ('4', 'R'), ('5', 'F'), ('7', 'V'), ('9', 'I'), ('1', 'O')]

    for j in xrange(10):
        for i in xrange(test.count(blech[j][1])):
            answer += blech[j][0]
            test = remove_char(test,int(blech[j][0] ))
    answer = "".join(sorted(list(answer)))
    print test
    return answer

def number_present(s, n):
    for i in set(numbers[n]):
        if not s.count(i) >= numbers[n].count(i):
            return False
    return True

def remove_char(s, n):
    s = list(s)
    for i in numbers[n]:
        s.remove(i)
    return "".join(s)

if __name__=="__main__":
    for i in xrange(int(raw_input())):
        print "Case #{}: {}".format(i+1, case(i))
        #"Case #{}: {}".format(i+1, case(i))
