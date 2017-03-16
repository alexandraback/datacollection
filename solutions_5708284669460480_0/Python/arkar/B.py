# Part 1: What's the maximum number of words

# If there is no suffix that is a prefix, easy

# Starting position 0
# New position: length of the string - length of longest suffix that is a prefix

# Expected number of right appearances: Simulate??
# Also: For each combination of prefixes: Keep the probability that it is there

# Tricky to code
import random
import itertools
import collections
import copy


NUM_REPS = 2000000

#NUM_REPS = 20

# We iterate over each character
# Distribution of all suffixes so far that are prefixes
# Then, for each suffix: The chance it survives is the keyboard count

T = int(raw_input())
for i in xrange(T):
    k, l, s = map(int, raw_input().split())
    keyboard = raw_input()
    target = raw_input()

    allPrefixes = set()
    for j in xrange(1, len(target)):
        allPrefixes.add(target[0:j])
#    print allPrefixes
    longestSuffix = 0
    for j in xrange(len(target) - 1, 0, -1):
        suffix = target[j: len(target)]
#        print suffix
        if suffix in allPrefixes:
            longestSuffix = max(longestSuffix, len(suffix))

    # see whether possible at all
    availableChars = set()
    charCounts = collections.Counter()
    for j in xrange(len(keyboard)):
        availableChars.add(keyboard[j])
        charCounts[keyboard[j]] += 1

    unfoundChars = False
    for j in xrange(len(target)):
        if target[j] not in availableChars:
            unfoundChars = True
            break

    if unfoundChars:
        maxx = 0
        print "Case #%s: %s" % (i + 1, 0.0)
    else:
        maxx = 0
        startingPos = 0
        while startingPos + len(target) - 1 <= s - 1:
            maxx += 1
            startingPos += len(target) - longestSuffix

        totProbs = 0.0
        prevProbs = {"": 1.0}
        allPrefixes.add(target)

        for j in xrange(s):
            newProbs = {"": 1.0}
            # Probability an occurrance ends here
#            print allPrefixes
            for prefix in allPrefixes:
#                print prefix[:len(prefix) - 1], prefix[:len(prefix) - 1] in prevProbs
                if prefix[:len(prefix) - 1] in prevProbs:
                    newProbs[prefix] = prevProbs[prefix[:len(prefix) - 1]]*float((charCounts[prefix[len(prefix)-1]]))/float(k)

#            print newProbs
            if target in newProbs:
                totProbs += newProbs[target]
#            print j, newProbs
            prevProbs = copy.copy(newProbs)

#        print maxx

#        print totProbs
        print "Case #%s: %s" % (i + 1, maxx - totProbs)



#         maxx = 0
#         startingPos = 0
#         while startingPos + len(target) -1 <= s - 1:
#             maxx += 1
#             startingPos += len(target) - longestSuffix
#
#         tot = 0
#         for j in xrange(NUM_REPS):
#
#             _random, _int = random.random, int
#             pos = "".join([keyboard[_int(_random() * k)] for sssss in itertools.repeat(None, s)])
# #            print pos
#             for indexStart in xrange(s - l + 1):
#                 if pos[indexStart: indexStart + l] == target:
#                     tot += 1
#             # TODO: Hash
