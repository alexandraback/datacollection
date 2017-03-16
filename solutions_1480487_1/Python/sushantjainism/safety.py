#first quest - safety in numbers

def safety():
	test_cases = int(raw_input())
	for test in range(test_cases):
		scores = map(int, raw_input().split())
		total_contestants = scores[0]
		sum_scores = reduce(lambda x,y: x+y, scores[1:])
		print 'Case #%d:'%(test+1),
		req_scores = list()
		temp_sum = 0.0
		cnt = 0
		for i in range(total_contestants):
			req_score = (200.0/total_contestants) - ((scores[i+1] * 100) / float(sum_scores))
			if req_score < 0:
				
				temp_sum += req_score;
				cnt += 1
				req_score = 0.0;			
			req_scores.append(req_score)
		if temp_sum < 0.0:
			
			distribute = (-temp_sum) / ((total_contestants - cnt) * 1.0);
			for index,sc in enumerate(req_scores):
				if sc != 0.0:
					req_scores[index] = sc - distribute;
		
		for scr in req_scores:
			print '%.6f'%(scr),		
			
			#if req_score < 0:
				#req_score = 0
			
			#print '%.5f'%(req_score),
		
		print
	return
if __name__ == '__main__':
	safety()
