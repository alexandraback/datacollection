#!/usr/bin/env python3.2
#coding=UTF-8

'''

Google Code Jam 2014
Qualification Round
Problem C
Minesweeper Master

Instructions:
	chmod u+x process.py
	./process.py <input_file >output_file
	# stderr output is intended to display on a console

Notes:
	* because it's based on something as sophisticated as minesweeper, this problem initially appears like it might be very difficult... until you actually get to the important details of the problem
	* seems like there should be a pretty simple system for arranging the mines so you can win in one click, if it's possible
	* it should be possible for all but a nearly-full board
	* at a basic level, I guess all the mines would be packed together at the top or top-left of the grid, and you would click the opposite end of the grid
	* a row of 0 cells at the bottom end requires a row of non-mines above them
	* at the moment, I've still just got a *hunch* that packing them all in the top-left and clicking the bottom-right is always going to work if it's possible
	* I guess we'll have to consider a few basic cases:
	
	* yes:
		********
		........
		.......c
	* yes:
		********
		********
		*******c
	* yes:
		********
		****....
		........
		.......c
	* yes:
		********
		******..
		........
		.......c
	* ???:
		********
		*******.
		........
		........
		.......c
	* becomes:
		********
		******..
		*.......
		........
		.......c
	* ???:
		********
		*******.
		........
		.......c
	* becomes:
		********
		*****...
		*.......
		*......c
	* and with that last example, it becomes clear that this problem might not be as simple as I'd originally thought...
	* but I'm still convinced there is a relatively simple solution - it's just not simple to work it out or prove that it works
	* the objective is to avoid those narrow gaps without any adjacent 0 cells
	
	* we could start with a grid of all mines, and search for chunks to eliminate to reduce the mine count down to the expected value, eliminating chunks in such a way that everything's connected to the starting 0-square
	* is it possible that for some inputs, a 1-click win is possible, but not with the click in the corner? I don't think so - I think it's safe to use an algorithm which always puts the click in the corner
	* Okay, let's analyse the possible solutions as a function of the number of spaces (non-mines) we're looking for...
		* 0 is an automatic win in 0 clicks... but M < R*C so this won't happen
		* 1 is winnable by clicking on the space
		* 2 is not winnable in 1 click.... unless there are no mines and the grid is 2x1??? - shit... that's another anomaly we have to work into our system
			* or if the grid is 1 wide or 1 tall, even if there are mines
		* 
	
	* there can be 1 non-0 cell with no adjacent 0 cells - iff it's the only non-mine cell (of course it's the one you click on)
	* if there's more than 1 non-mine cell, it's necessary to click on a 0-cell to win, and in this case, every non-0 cell must be adjacent to a 0-cell (and of course they must all be in 1 connected group)
		* 
	
	* is it possible to break the problem down, using a system to populate part of the grid, but then try all combinations for a small remaining region or something???
	* would it be a good idea to handle small grids as special cases, applying an algorithm or trying combinations, rather than using a simple system?
	
	
	* 50x50 is the largest grid to be handled
	* 1x1 is the smallest
	* there's always at least 1 space (there may be 0 mines)
	* 1 space is handled as a special case - easy to handle
	* >1 spaces requires a contiguous group of 0-cells
	* if a cell is a 0-cell, it will be surrounded by 8 cells which are either non-mines or off the grid edge
	* so in the case of a corner cell, only 3 spaces are required around it (or less if it's a tiny grid)
	* 
	
	
	proof that the click point can always be the corner:
		* for 1 space, it doesn't matter where it is, so the corner is fine
		* if the corner is empty, it must be adjacent to a 0-cell to show up
		* no matter which adjacent cell that 0-cell is in, it implies that the corner is also a 0-cell
			* this reasoning also applies to edges
		* so there is no situation where the .........
	
	* let's try to make an algorithm that works with large grids (ie. it may fail below certain dimensions):
		* fill in reading order, top to bottom, left to right
		* if there's a gap of 1 at the end of the last line of mines, we have to remove a mine from this line and add it to the next line instead
	
	* I'm going to take a break for a bit
	
	* is it possible to build it up from the inside-out....
		* like eg. if there exists a solution in RxC space with M mines and mines around the outside, then there exists a solution in RxC+1 space with M+R mines and mines around the outside (and it can be easily derived from the original solution)
		* then we'd need some base cases of some kind
		* with 0 mines it's always possible
		* with 2R + 2C - 4 mines it's always possible? (when R>1 and C>1, at least?) ... nope - a 1x2 gap doesn't work
		* 
	
	* can we precalculate a 50x50x50 table (125000 entries) generated by doing the problem in reverse (or forwards?) in our own time?
	* each table entry could specify another table entry from which the layout was derived, plus a rule that was followed to derive it, effectively storing compact instructions for rebuilding the layout, by following the chain of links
	* but we'd have to be sure that our set of rules really can generate all possible combinations of those 3 numbers - otherwise missing entries would just be unknown, rather than impossible
	* I'm not sure this can work out, because if we only retain 1 possible way of solving problem size x, we won't know if problem size x+1 could be solved by extending some other solution for size x that we haven't retained
	* still, the precalculation idea may have some kind of promise...
	
	* we could precalculate all possible 5x5 grids (there's about 32 million of them - although this increases if you allow 5x5 or smaller) and use the results to populate our table for up to 5x5 size
	* then we could use a simple system/algorithm to generate grids with both dimensions larger than 5
	* what if only one dimension is larger than 5?
	* maybe we need separate algorithms for widths up to 5?
	* also, we can transpose to apply solutions/algorithms for width x to work at height x instead
	* I think I'll code individual routines for widths up to 5, and a single routine for widths over 5
	* this is seeming like a surprisingly hard problem...
	
	* to precalculate all solutions up to 5x5:
		* 32M + 1M + 1M/32 + ....
		* 2^5*5 + 2^5*4 + 2^5*3 + 2^5*2 + 2^5*1 + 2^4*4 + 2^4*3 + 2^4*2 + 2^4*1 + 2^3*3 + 2^3*2 + 2^3*1 + 2^2*2 + 2^2*1 + 2^1*1 = approx 35M?
		* of course actually storing the solutions may be a problem... although I suppose they'd only take max 4 bytes each (25 bits for the mine map, plus 5 bits for the click position, makes 30 bits total - the R&C values are already implied by the location in the table)
		* you'd also want to be able to very quickly check each of those possible solution layouts to see if it's a 1-click win
	
	
	* I think we should be able to find/store shapes of spaces with 1-click wins, indexed by number of spaces (which can be quickly calculated from the number of mines and grid size)
	* I guess you'd also have to store the grid size, to allow you to fit it into various size grids
	* 
	
	
	Considering various classes of problem:
		1 space:
			* all 1-space problems are solvable by filling a grid with mines and replacing one with the click
		0 mines:
			* all 0-mines problems are solvable by setting up an empty grid and placing the click anywhere (let's say in the bottom-right)
		1*x:
			* all 1*x grids are solvable
			* fill with mines, remove all spaces from one end, and click at the very end (which is a 0-cell, except for 1-space problems, which are solvable as mentioned above)
		2*x, x>1:
			* all 2*x grids with an even number of mines are solvable, except for 2*2 with 2 mines
			* just put all the mines at one end, all the spaces at the other, and click in the corner at a 0-cell
		3*x, x>2:
			* all 3*x grids with a grid 3 units wide or wider and a multiple of 3 mines are solvable
			* 
	
	* trying to fit 2 mines into a 3*5 space, I'm realising that even with grids this size, it's easy to miss possibilities - so it would be safer to try a combinatorial solution of some kind
	* let's analyse the problem size a bit:
		* 5*5 grid gives 25 cells
		* placing mines in that is 25 choose M
		* the worst case is 25 choose 12 = 4457400
		* so that's 4.4M board configurations to check for the worst possible test case in the small data set
			* and with 230 test cases, that's 1025202000 board configurations to check overall
			* and for each board configuration, we have to test if it's winnable... and that's not going to be super-quick
				* I guess a basic algorithm would start by finding a 0-cell and then flood-filling out through all other 0-cells, and at the end, check if there are any spaces that weren't looked at (of course 1 space would be treated as a special case here)
		* 
	
	* I think my ideas about growing smaller solutions into bigger solutions were promising...
		* but the borders really present problems
		* that's why I gave examples that stipulated that the outside must be surrounded by mines
		* can we relax this restriction?
		* outside the grid borders, we conceptually have cells that aren't mines but also aren't spaces
		* imagine that we have a template shape with a number of spaces... and we know it's a shape that supports a 1-click win
		* we can overlay that on a grid to get a 1-click grid pattern with the required number of mines/spaces
		* it's also possible to overlay it partially off the edge/corner of the grid, in which case the spaces outside the grid would not be counted - but it's still a 1-click win
			* I'm beginning to think I'm just adding unnecessary complexity here - maybe I should abandon this idea
		* I'm worried about shapes that when parts are eliminated, become disconnected, for example:
			XXX              YY
			X    overlaid on YY with the connecting path out the left side
			XXX              YY
		* if our method of growing shapes ensures that they are always convex, then this won't be an issue
	
	* the smaller number of test cases for the large dataset suggests...
		* that the expected code for the large dataset is slower than that for the small dataset
		* or maybe they needed to construct test data by hand and they didn't want to construct so much??
	
	* okay, we need to do something...
		* let's make an algorithm that works for grids a certain size or over
		* click cell is always bottom-right corner
		* we populate with mines in reading order - top to bottom, left to right
		* when placing mines, we have to avoid leaving spaces that are no longer next to a 0 cell
		* ......
		* no, I don't think filling with mines in reading order is a good strategy
	
	* let's try growing spaces from the click corner
	* begin with 2*2 spaces in the corner, since that's the smallest non-1-space shape that works outside of very narrow grids
	* no - let's begin with 1*1 spaces in the corner
	* possible ways to expand:
		* take a cell that is not a space and make it a space, then worry about whether it violates the constraints and perform fix-up
		* take a border cell (that is a space, but not a 0-cell), and make it a 0-cell by making all non-spaces around it (within the grid) into spaces
	* a 1-click shape consists of connected pattern of 0-cells, plus a border of non-0-cell spaces
	* if we're working in the corner, the border consists of a non-circular chain of cells, where the next in the chain can be determined in O(1), making it possible to follow the chain in O(N) time, where N is the length of the chain, and is in the order of roughly the square root of the number of spaces
	* of course we can keep growing and growing the shape by repeatedly picking a border cell and making all surrounding cells into spaces...
		* and using this technique, I'm quite certain it's possible to produce any possible single-click pattern
			* well, I'm not 100% sure about starting in the corner being okay, but aside from that
		* but this involves a decision (which border cell to change) and I'm worried about the possibility of making the wrong decision
		* we could always try to pick the cell that involves creates the least number of spaces
			* but I can't be certain that that won't force us later to pick a cell that creates more spaces than would otherwise be necessary
	* let's say we made an incorrect decision and couldn't meet the target mine count - is there some way for us to recover mines?
		* well, the nice thing about our growth system so far is that the growth rules preserve the 1-click property
		* and having growth only, means we don't have to worry about termination conditions not being reached in reasonable time - every change increases the spaces by at least 1
		* obviously any reduction rules would also have to preserve the 1-click property
		* following our pattern so far (starting in the corner and all that), it seems that the first expansion of a flat border would increase spaces by 2, but all other expansions along that row would increase spaces by 1
		* so that means that we're (in general, with large enough grids) only ever going to be a maximum of 1 unit above our count
		* so we would only need a reduction rule to eliminate a single mine, and it would only have to be applied once, optionally, after the growth loop
		* but if the required spaces is too small, and we don't even have a couple of blank rows at the bottom, this reasoning won't hold
			* every expansion along the bottom row creates 2 spaces - not 1
			* so to make that clear, even with large grids, if the mines is also large, the situation changes
	* we can increase spaces by 1 by eliminating a "jutting corner" (definition: in a simple convex shape extending from the lower-right corner, a "jutting corner" is a mine along the border with spaces to the right, below and below-right)
		* but if there are no jutting corners, we can't do this
		* but patterns with no jutting corners can possibly be rearranged into patterns with jutting corners
		* 
	
	* it would be nice if there was an ASCII character (preferably found on the keyboard) with a dot in the center of the character - the dot in the corner makes diagrams a little confusing
	
	* another try:
		* start with 0 mines, and add in reading order from top-left
		* but if adding a mine would violate the 1-click property, instead move onto the next position in reading order and try that
			* effectively, this means we end each row of mines 2 cells before the edge of the row
		* eventually, we will reach a situation where adding a single mine is impossible:
			*******..
			*******..
			*******..
			.........
			........c
		* clearly it's possible to get additional mines into the above (by adding in pairs)
		* and clearly it's possible to get additional mines in without adding in pairs, by removing some existing mines to compensate
		* possible solutions:
			* work out a system of removing mines when a dead end is reached
			* add rules for adding mines in pairs (clearly this alone won't allow us to properly check for a possible solution)
			* change our mine-adding order so that this dead-end is never reached (ie. we only reach a dead-end for adding single mines when it's genuinely impossible to reach the next mine count with a 1-click arrangement)
		* what about if we always try to add in "jutting corners" when possible?
		* or, instead, we try to never eliminate jutting corners unless we can't avoid it?
		* what if we work out some kind of "potential energy" analogue for jutting corners, and avoid reducing it unless necessary?
			* so at any given stage, we either have a number of jutting corners, or the potential to generate a number of jutting corners, and we add the two
		* 
	
	* another try:
		* start by eliminating entire rows or columns of spaces (from the top or left), until we're close to our target spaces
		* 
	
	* another try:
		* seems that the main effect of increasing mines from 0 is that you don't consider the really tricky cases until the end of the process
		* start with 2*2 spaces in the bottom-right corner (obviously we've already checked that a single space won't be the solution)
		* begin by adding spaces in pairs, growing up and growing to the left from the starting position
		* once we've grown up and to the left once each, we have the potential to grow by 1 unit by eliminating the jutting corner
		* once we've reached the stage of having a full rectangle with a 2-wide gap on the bottom and right, we can eliminate single mines in reverse reading order
		* so this means that 4 spaces are possible, 6 spaces are possible, 8 spaces are possible, 9 spaces are possible (by eliminating the jutting corner) and any amount of spaces above 9 are possible (by eliminating the required parts of the edges, plus the jutting corner, or by eliminating all the edges, then enough single mines
		* I think I've got it.... and I have 2 hours to implement it
	
	* summarising what I've worked out, from scratch:
		* a solution for x*y can be used for y*x by swapping the dimensions, solving, then transposing the solution
		* for convenience, we always start with a grid full of mines, and replace mines with spaces
		* for convenience, we always put the click in the top-left
		* 1-space is always possible - just put the click in the top-left
		* 1*x is possible - just add spaces up to the necessary count before putting the click in the left - this handles 1*1
		* 2*x (x>1) is possible for even numbers of mines - add spaces in pairs from left to right
		* 3*3 or larger - anything larger than the above can be handled with this algorithm:
			start with all mines, except 2*2 spaces in the top-left, with the click in the very top-left square
			follow the following rules until either we reach our target spaces/mines (success) or we overshoot (failure/impossible)
			add 2 spaces below the original 4 spaces
			if we're too big, fail
			add 2 spaces to the right of the original 4 spaces
			if we're too big, fail
			while we're more than 1 space away from our target and we haven't reached the end of the grid: add 2 spaces to the right of the original 4
			while we're more than 1 space away from our target and we haven't reached the end of the grid: add 2 spaces below the original 4
			remove mines 1 at a time, in reading order, from the remaining rectangle, until we reach our target
			# note: if the above 2 while loops didn't leave us with a rectangle, it's because we already reached 1 within our target, and we either have to remove just the first mine in the rectangle, or none at all
		

'''

################################################################################


def read_case(id, input):
	R,C,M = [int(x) for x in input.readline().split()]
	return R,C,M

'''
	* summarising what I've worked out, from scratch:
		* a solution for x*y can be used for y*x by swapping the dimensions, solving, then transposing the solution
		* for convenience, we always start with a grid full of mines, and replace mines with spaces
		* for convenience, we always put the click in the top-left
		* 1-space is always possible - just put the click in the top-left
		* 1*x is possible - just add spaces up to the necessary count before putting the click in the left - this handles 1*1
		* 2*x (x>1) is possible for even numbers of spaces/mines - except 2 spaces -- add spaces in pairs from left to right
		* 3*3 or larger - anything larger than the above can be handled with this algorithm:
			start with all mines, except 2*2 spaces in the top-left, with the click in the very top-left square
			follow the following rules until either we reach our target spaces/mines (success) or we overshoot (failure/impossible)
			add 2 spaces below the original 4 spaces
			if we're too big, fail
			add 2 spaces to the right of the original 4 spaces
			if we're too big, fail
			while we're more than 1 space away from our target and we haven't reached the end of the grid: add 2 spaces to the right of the original 4
			while we're more than 1 space away from our target and we haven't reached the end of the grid: add 2 spaces below the original 4
			remove mines 1 at a time, in reading order, from the remaining rectangle, until we reach our target
			# note: if the above 2 while loops didn't leave us with a rectangle, it's because we already reached 1 within our target, and we either have to remove just the first mine in the rectangle, or none at all
'''

def solve_larger(R,C,M):
	if R < 3: raise Exception("R < 3")
	if C < 3: raise Exception("C < 3")
	
	grid = new_grid(R,C)
	
	S = R*C - M  # required spaces
	s = 0
	
	# we don't need to handle 1 space here
	
	grid[0,0] = '.'
	grid[0,1] = '.'
	grid[1,0] = '.'
	grid[1,1] = '.'
	s += 4
	if s == S: return grid
	if s > S: return None
	
	grid[2,0] = '.'
	grid[2,1] = '.'
	s += 2
	if s == S: return grid
	if s > S: return None
	
	grid[0,2] = '.'
	grid[1,2] = '.'
	s += 2
	if s == S: return grid
	if s > S: return None
	
	c = 3
	while (s < S-1) and (c < C):
		grid[0,c] = '.'
		grid[1,c] = '.'
		s += 2
		c += 1
	
	r = 3
	while (s < S-1) and (r < R):
		grid[r,0] = '.'
		grid[r,1] = '.'
		s += 2
		r += 1
	
	for r in range(2,R):
		for c in range(2,C):
			if s == S: return grid
			grid[r,c] = '.'
			s += 1
	
	if s == S: return grid
	
	raise Exception("solve_larger failed")
	
	return None # this should be unreachable

def new_grid(R,C):
	# init the grid with all mines
	grid = dict()
	for r in range(R):
		for c in range(C):
			grid[r,c] = "*"
	return grid

def solve_1space(R,C,M):
	if (R*C - M) != 1: raise Exception("R not 1")
	
	grid = new_grid(R,C)
	grid[0,0] = '.'
	return grid

def solve_1high(R,C,M):
	if R != 1: raise Exception("R not 1")
	
	grid = new_grid(R,C)
	for c in range(C-M):
		grid[0,c] = '.'
	return grid

def solve_2high(R,C,M):
	if R != 2: raise Exception("R not 2")
	if C < 2: raise Exception("C not < 2")
	
	if (R*C - M) == 2: return None
	if (M%2) != 0: return None
	
	grid = new_grid(R,C)
	for c in range(C-int(M/2)):
		grid[0,c] = '.'
		grid[1,c] = '.'
	return grid

def solve_wide(R,C,M):
	if R > C: raise Exception("R > C")
	
	if M == (R*C-1):
		return solve_1space(R,C,M)
	elif R == 1:
		return solve_1high(R,C,M)
	elif R == 2:
		return solve_2high(R,C,M)
	else:
		return solve_larger(R,C,M)
	
	

def transpose(R,C,grid):
	# pass-through if we don't have a proper grid
	if not grid:
		return grid
	
	# swap x & y dimensions
	out = dict()
	for (r,c),value in grid.items():
		out[c,r] = value
	return out

def dumpgrid(R,C,grid):
	# we use a dict for our grid, and we pass the dimensions around explicitly
	# we store the output characters in the grid, so we can output them directly
	# the click point is implied in the top-left - we don't explicitly store this
	# the top-left is empty in all our solutions
	if grid[0,0] != '.':
		raise Exception("click position isn't clear of mines")
	
	out = ""
	for r in range(R):
		for c in range(C):
			if r == 0 and c == 0:
				out += "c"
			else:
				out += grid[r,c]
		out += "\n"
	return out

def solve(R,C,M):
	if R < C:
		return solve_wide(R,C,M)
	else:
		return transpose(C,R,solve_wide(C,R,M))

def solve_case(id, case):
	R,C,M = case
	solution = solve(R,C,M)
	return "Case #{}:\n{}".format(id, dumpgrid(R,C,solution) if solution else "Impossible\n")


def prepare():
	def prepare_data():
		return None
	
	global prepared_data
	prepared_data = prepare_cached(prepare_data, 'prepared_data.cached')


################################################################################


from sys import stdin, stdout, stderr
import time
import math
import pickle
import io

execution_timer = time.time
#execution_timer = time.clock
debugging = 1


################################################################################


def debug(message):
	if debugging:
		stderr.write(message() if hasattr(message, '__call__') else message)

def report(message):
	stderr.write(message)

def prepare_cached(prepare_data, pickle_path='data.pickle'):
	try:
		data = pickle.load(io.open(pickle_path, 'rb'))
		report("Loaded {}.\n".format(pickle_path))
	except IOError:
		data = prepare_data()
		report("Prepared {}.\n".format(pickle_path))
		pickle.dump(data, io.open(pickle_path, 'wb'))
	return data

def main():
	t0 = execution_timer()
	#prepare()
	t1 = execution_timer()
	report("Completed preparation in {:.6f} seconds.\n".format(t1 - t0))
	
	T = int(stdin.readline())
	for case_id in range(1,T+1):
		report("Processing test case {} of {} (output {}). {:.0f} seconds elapsed.".format(case_id, T, case_id-1, execution_timer() - t1))
		report("\n" if debugging else "\r")
		stderr.flush()
		stdout.write(solve_case(case_id, read_case(case_id, stdin)))
		stdout.flush()
	
	t2 = execution_timer()
	report("Processed {} test cases in {:.6f} seconds.                           \n".format(T, t2 - t1))
	report("Total time: {:.6f} seconds.\n".format(t2 - t0))

if __name__ == '__main__':
	main()

