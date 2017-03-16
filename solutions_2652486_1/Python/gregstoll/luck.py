#!/usr/bin/python
import os, sys, math, random

global primes
primes = [2, 3, 5, 7]

def get_prime_factors_small1(value):
    global primes
    factor_count = [0, 0, 0, 0]
    while value > 1:
        for (i, p) in enumerate(primes):
            if p * (value/p) == value:
                factor_count[i] += 1
                value = value / p
    return factor_count

def solve_small1(m, n, values):
    # n = 3, m = 5
    # 3 numbers between 2 and 5 (inclusive)
    min_primes = [0, 0, 0, 0]
    total_primes = [0, 0, 0, 0]
    for v in values:
        factor_count = get_prime_factors_small1(v)
        if (factor_count[0] == 2 and factor_count[1] == 1 and factor_count[2] == 1):
            # _very_ lucky!
            return [4,3,5]
        for i in range(len(min_primes)):
            min_primes[i] = max(min_primes[i], factor_count[i])
            total_primes[i] += factor_count[i]
    #print min_primes
    #print total_primes
    #if sum(min_primes) > 3:
    #    print 'ERROR - min_primes is %s too big for values %s' % (min_primes, values)
    #    sys.exit(1)
    guesses = []
    # 3's and 5's stand alone
    for i in range(min_primes[1]):
        guesses.append(3)
        total_primes[1] -= 1
    for i in range(min_primes[2]):
        guesses.append(5)
        total_primes[2] -= 1
    if len(guesses) == 3:
        return guesses
    if min_primes[0] > 0:
        num_left = 3 - len(guesses)
        while min_primes[0] > num_left:
            guesses.append(4)
            if len(guesses) == 3:
                return guesses
            min_primes[0] -= 2
            num_left = 3 - len(guesses)
    while len(guesses) < 3:
        guesses.append(2)
    return guesses

def solve_small2(m, n, values):
    # n = 12, m = 8
    # 12 numbers between 2 and 8 (inclusive)
    min_primes = [0, 0, 0, 0]
    total_primes = [0, 0, 0, 0]
    for v in values:
        factor_count = get_prime_factors_small1(v)
        for i in range(len(min_primes)):
            min_primes[i] = max(min_primes[i], factor_count[i])
            total_primes[i] += factor_count[i]
    #print min_primes
    #print total_primes
    #if sum(min_primes) > 3:
    #    print 'ERROR - min_primes is %s too big for values %s' % (min_primes, values)
    #    sys.exit(1)
    guesses = []
    # we get about half each time
    estimated_fives = int(round(float(total_primes[2] * 2) / len(values)))
    estimated_sevens = int(round(float(total_primes[3] * 2) / len(values)))
    # 5's and 7's stand alone
    for i in range(min_primes[2]):
        guesses.append(5)
        total_primes[2] -= 1
        estimated_fives -= 1
    for i in range(min_primes[3]):
        guesses.append(7)
        total_primes[3] -= 1
        estimated_sevens -= 1
    if len(guesses) == 12:
        return guesses
    for i in range(int(math.floor(estimated_fives))):
        guesses.append(5)
        estimated_fives -= 1
        if len(guesses) == 12:
            return guesses
    for i in range(int(math.floor(estimated_sevens))):
        guesses.append(7)
        estimated_sevens -= 1
        if len(guesses) == 12:
            return guesses
    # we get about half each time
    estimated_twos = int(round(float(total_primes[0] * 2) / len(values)))
    estimated_threes = int(round(float(total_primes[1] * 2) / len(values)))

    if estimated_twos < min_primes[0]:
        # whoa
        estimated_twos = min_primes[0]
    if estimated_threes < min_primes[1]:
        # whoa
        estimated_threes = min_primes[1]
    # OK! Each three can be with at most one two
    # but two's can be up to 3 slots per entry
    estimated_twos -= (12 - len(guesses) - estimated_threes)
    while len(guesses) < 12 and estimated_threes > 0:
        num_left = 12 - len(guesses)
        # let's start guessing!
        num_three_slots_left = min(num_left, estimated_threes)
        number_of_two_slots_left = num_three_slots_left + 3 * max(num_left - num_three_slots_left, 0)
        #number_of_two_slots_left = min(num_left, estimated_threes) + max(num_left - estimated_threes, 0) * 3
        #print "TODO est_threes %d est_twos %d num_two_slots_left %d num_left %d" % (estimated_threes, estimated_twos, number_of_two_slots_left, num_left)
        if random.random() < (float(estimated_twos) / number_of_two_slots_left):
            estimated_twos -= 1
            guesses.append(6)
        else:
            guesses.append(3)
        estimated_threes -= 1
    while len(guesses) < 12 and estimated_twos > 0:
        num_left = 12 - len(guesses)
        # let's start guessing!
        # every number gets at least one 2, i guess
        number_of_two_slots_left = num_left * 2
        # FFV - may be too uniform?
        num_to_guess = 2
        if (random.random() < ((float(estimated_twos - num_left)/number_of_two_slots_left))):
            num_to_guess *= 2
            estimated_twos -= 1
        number_of_two_slots_left -= 1
        if (random.random() < ((float(estimated_twos - num_left)/number_of_two_slots_left))):
            num_to_guess *= 2
            estimated_twos -= 1
        #twos_to_use = 1 + int(math.floor(float(estimated_twos - num_left)/number_of_two_slots_left))
        #if random.random() < ((float(estimated_twos - num_left)/number_of_two_slots_left) - twos_to_use):
        #    twos_to_use += 1
        #estimated_twos -= twos_to_use
        #guesses.append(int(math.pow(2, twos_to_use)))
        guesses.append(num_to_guess)
    while len(guesses) < 12:
        # umm...
        #print 'AAAAA'
        guesses.append(2)
    return guesses



def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        (r, n, m, k) = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        print 'Case #%d:' % (caseNum+1)
        for i in range(r):
            values = [int(x) for x in fileLines[index][:-1].split(' ')]
            index += 1
            answer = solve_small2(m, n, values)
            answer.sort()
            print "%s" % (''.join([str(x) for x in answer]))

if __name__ == '__main__':
    main(sys.argv[1])
