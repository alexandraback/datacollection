from pprint import pprint as pp 
from collections import defaultdict
import itertools
import sys
import time


def getFakes(submissions, source_only_first_words, source_only_second_words):
    sys.stderr.write(".")
    first_words_seen = set(source_only_first_words)
    second_words_seen = set(source_only_second_words)
    fakes = 0
    for subm in submissions:
        if subm[0] in first_words_seen and subm[1] in second_words_seen:
            fakes = fakes + 1
        first_words_seen.add(subm[0])
        second_words_seen.add(subm[1])
    return fakes

def partition_into_subsets(submissions):
    set1 = [submissions[0]]
    set1_first_terms = set()
    set1_second_terms = set()
    set1_first_terms.add(submissions[0][0])
    set1_second_terms.add(submissions[0][1])
    set2 = []
    for subm in submissions[1:]:
        if subm[0] in set1_first_terms or subm[1] in set1_second_terms:
            set1.append(subm)
            set1_first_terms.add(subm[0])
            set1_second_terms.add(subm[1])
        else:
            set2.append(subm)
    if len(set2) > 1:
        set2 = partition_into_subsets(set2)
        return [set1] + set2
    elif len(set2) == 1:
        return [set1] + [set2]
    else: # empty set2
        return [set1]

num_cases = int(raw_input())  # read a line with a single integer
    
for casenum in xrange(num_cases):
    num_submissions = int(raw_input())
    sys.stderr.write('case '+str(casenum)+" - lines:"+str(num_submissions)+'\n')
    submissions = []
    for r in xrange(num_submissions):
        s = raw_input()
        submissions.append(s.split(" ",2))
    ###
    #print submissions
    first_word_count = defaultdict(int)
    second_word_count = defaultdict(int)
    for subm in submissions:
        first_word_count[subm[0]] = first_word_count[subm[0]] + 1
        second_word_count[subm[1]] = second_word_count[subm[1]] + 1 
    submission_subset = []
    source_only_first_words = set()
    source_only_second_words = set()
    for subm in submissions:
        # if neither word is used elsewhere, we don't have to consider this
        # if one word isn't used elsewhere, it can't be a duplicate, but could 
        # be a source for the other word -- we'll see if we can omit those, just 
        # assume they are above any possible duplicates
        if first_word_count[subm[0]] == 1 and second_word_count[subm[1]] == 1: 
            continue
        if first_word_count[subm[0]] == 1:
            source_only_second_words.add(subm[1])
            continue
        if second_word_count[subm[1]] == 1: 
            source_only_first_words.add(subm[0])
            continue
            
        submission_subset.append(subm)
    #print submission_subset
    submission_subset2 = []
    fake_count = 0
    for subm in submission_subset:
        if subm[0] in source_only_first_words and subm[1] in source_only_second_words:
            fake_count = fake_count + 1
            continue
        submission_subset2.append(subm)
    # I think exhaustive search comes now
    sys.stderr.write("# left to exhaustively search: "+str(len(submission_subset2))+"\n")
    max_fakes = 0
    if len(submission_subset2) > 0:
        subsets = partition_into_subsets(submission_subset2)
        sys.stderr.write("Subsets: "+repr(subsets)+"\n")
        time.sleep(2)
        # itertools.permutations(subset)
        max_fakes = sum([max([getFakes(subs, source_only_first_words, source_only_second_words) for subs in sorted(subset, key=lambda s: first_word_count[s[0]]+second_word_count[s[1]] ) ]) for subset in subsets])
        sys.stderr.write("\n")
    ###
    print "Case #{}: {}".format(casenum+1, fake_count+max_fakes)
