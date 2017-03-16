#!/usr/bin/env python
K=input()
replace = "yhesocvxduiglbkrztnwjpfmaq"
for i in range(K):
    S = raw_input()
    SN = ""
    for j in S:
        if ord('a') <= ord(j) <= ord('z'):
            SN = SN + replace[ord(j) - ord('a')]
        else:
            SN += j
    print "Case #%d: %s" % (i + 1, SN)
