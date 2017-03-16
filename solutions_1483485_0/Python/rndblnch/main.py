#!/usr/bin/env python
# -*- coding: utf8 -*-

__author__    = "renaud blanch <rndblnch at gmail dot com>"
__copyright__ = "Copyright © 2011–2012 - Renaud Blanch"
__licence__   = "GPLv3 [http://www.gnu.org/licenses/gpl.html]"

from common import nt, ni, nl, line


"""
Speaking in Tongues
"""

english = """
aoz
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
q
"""

googlerese = """
yeq
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
z
"""

assert len(set(googlerese)) == 28

from string import maketrans
trans = maketrans(googlerese, english)


T = ni(); nl()
for X in xrange(T):
	print "Case #%s:" % (X+1),
	for s in line():
		print s.translate(trans),
	print
