import sys

n = int(sys.stdin.readline())
for i in range(n):
	inputline = sys.stdin.readline().strip()
	inputparams = inputline.split()

	h = int(inputparams[0])
	w = int(inputparams[1])
	d = int(inputparams[2])

	for j in range(h):
		inputline = sys.stdin.readline().strip()
		pos = inputline.find("X")
		if -1 != pos:
			x = pos
			y = j

	imagesset = set([(x, y)])
	imagesdict = {x: set([y])}

	while True:
		addedimages = set()

		for j in range(4):
			for original in imagesset:
				originalx, originaly = original

				if 0 == j:
					imagex = 1 - originalx
					imagey = originaly
				elif 1 == j:
					imagex = originalx
					imagey = 1 - originaly
				elif 2 == j:
					imagex = 2 * w - originalx - 3
					imagey = originaly
				else:
					imagex = originalx
					imagey = 2 * h - originaly - 3

				if (0 < imagex) and (w - 1 > imagex) and (0 < imagey) and (h - 1 > imagey):
					continue

				if (imagex - x) ** 2 + (imagey - y) ** 2 > d ** 2:
					continue

				if (imagex in imagesdict) and (imagey in imagesdict[imagex]):
					continue

				if imagex not in imagesdict:
					imagesdict[imagex] = set()
				imagesdict[imagex].add(imagey)
				addedimages.add((imagex, imagey))

		if 0 == len(addedimages):
			break
		else:
			imagesset = imagesset | addedimages

	uniqueimages = set()
	for image in imagesset:
		imagex, imagey = image
		if (imagex == x) and (imagey == y):
			continue

		sameasunique = False
		for uniqueimage in uniqueimages:
			uniquex, uniquey = uniqueimage

			if (uniquex - x) * (imagex - x) < 0:
				continue

			if (uniquey - y) * (imagey - y) < 0:
				continue

			if (uniquex - x) * (imagey - y) == (uniquey - y) * (imagex - x):
				sameasunique = True
				break

		if not sameasunique:
			uniqueimages.add(image)

	print "Case #%d: %d" % (i + 1, len(uniqueimages))	

