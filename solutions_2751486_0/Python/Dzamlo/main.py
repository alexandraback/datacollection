#! /usr/bin/env python

def is_vowel(c):
    return c in ('a','e','i','o','u')

def to_consonants_bool_list(s):
   return [not is_vowel(c) for c in s]

def find_group_starts(s,n):
    starts = []
    for i in xrange(len(s)-n+1):
       start = True
       for j in range(i, i+n):
          if not s[j]:
             start = False
             break
       if start:
           starts.append(i)
    return starts

def compute_n_value(s, n):
    s = to_consonants_bool_list(s)
    group_starts = find_group_starts(s,n)
    nb_group_starts = len(group_starts)
    n_value = 0
    if nb_group_starts > 0:
        group_start_idx = 0
        for i in xrange(len(s)-n+1):
            while group_start_idx < nb_group_starts-1 and group_starts[group_start_idx] < i:
                group_start_idx+=1
            if group_starts[group_start_idx] >= i:
               n_value += len(s)-(group_starts[group_start_idx]+n)+1
    return n_value
t = input()
for i in xrange(1, t+1):
    s,n = raw_input().split()
    n = int(n)
    print 'Case #%d: %d' % (i, compute_n_value(s,n))

