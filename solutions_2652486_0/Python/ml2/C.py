import sys
import math
import itertools

print  'Case #1:'
for testcase in xrange(1, int(sys.stdin.readline())+1):
	R,N,M,K = [int(w) for w in sys.stdin.readline().split()]

	for i in xrange(R):
		ks = [int(w) for w in sys.stdin.readline().split()]
		divisible_by_2 = False
		divisible_by_4 = False
		divisible_by_8 = False
		divisible_by_16 = False
		divisible_by_3 = False
		divisible_by_9 = False
		divisible_by_5 = False
		divisible_by_25 = False

		for val in ks:
			if val == 125:
				result =  555
				break
			elif val == 27:
				result =  333
				break
			elif val == 75:
				result =  355
				break
			elif val == 45:
				result =  335
				break
			elif val == 50:
				result =  255
				break
			elif val == 100:
				result =  455
				break
			elif val == 80:
				result =  445
				break
			elif val == 60:
				result =  345
				break
			elif val == 40:
				result =  245
				break
			elif val == 30:
				result =  235
				break
			elif val == 64:
				result =  44
				break
			elif val == 48:
				result =  344
				break
			elif val == 32:
				result =  244
				break
			elif val == 36:
				result =  334
				break
			elif val == 24:
				result =  432
				break
			elif val == 18:
				result =  233
				break
			elif val == 25:
				divisible_by_5 = True
				divisible_by_25 = True			
			elif val == 20:
				divisible_by_5 = True
				divisible_by_4 = True
				divisible_by_2 = True
			elif val == 16:
				divisible_by_2 = True
				divisible_by_4 = True
				divisible_by_8 = True
				divisible_by_16 = True 
			elif val == 12:
				divisible_by_2 = True
				divisible_by_4 = True
				divisible_by_3 = True
			elif val == 8:
				divisible_by_2 = True
				divisible_by_4 = True
				divisible_by_8 = True
		if result:
			print result
		else:
			if divisible_by_25:
				if divisible_by_4:
					print 455
				elif divisible_by_3:
					print 355
				elif divisible_by_2:
					print 255
				else:
					print 555
			elif divisible_by_16:
				if divisible_by_5:
					print 445
				elif divisible_by_3:
					print 443
				else:
					print 442
			elif divisible_by_9:
				if divisible_by_5:
					print 335
				elif divisible_by_4:
					print 334
				elif divisible_by_2:
					print 332
				else:
					print 333
			elif divisible_by_5:
				if divisible_by_4:
					if divisible_by_3:
						print 345
					else:
						print 245
				elif divisible_by_3:
					print 235
				else:
					print 225
			elif divisible_by_3:
				if divisible_by_4:
					print 234
				else:
					print 223
			else:
				print 222


